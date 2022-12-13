#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include "stdio.h"
#include <set>
#include <cmath>
#define int long long
#define mp make_pair
using namespace std;

/*
side note: You can BFS from the End to simply check all 
'a'elevations. I just did BFS from every starting point.
*/

int arr[100][500], used[100][500], dist[100][500];
int d1[9]={0,0,1,-1}, d2[9]={1,-1,0,0};
queue<pair<int,int>> q;
vector<pair<int,int>> v;
int finX,finY,mn=1e9;
string s;

void test(int a, int b, int c, int d){
 if(0<=a&&a<=40&&0<=b&&b<=s.size()-1&&used[a][b]==0&&arr[a][b]<=d+1){
   dist[a][b]=c+1;
   used[a][b]=1;
   q.push(mp(a,b));
   }
}

signed main(){
 ifstream file("d12.txt");
 if (file.is_open()){
   for(int i=0; i<41; i++){
     file >> s;
     for(int j=0; j<s.size(); j++){
       if(s[j]=='S'||s[j]=='a'){v.push_back(mp(i,j)); arr[i][j]=0;continue;}
       if(s[j]=='E'){finX=i,finY=j;arr[i][j]=25;continue;}
       arr[i][j]=s[j]-'a';
     }
   }
 }
 file.close();
for(int z=0; z<v.size(); z++){
  q.push(mp(v[z].first,v[z].second));
  for(int i=0; i<95; i++)for(int j=0; j<200; j++){used[i][j]=0,dist[i][j]=0;}
  used[v[z].first][v[z].second]=1;
 while(!q.empty()){
  pair<int,int> st=q.front();
   for(int i=0; i<4; i++){
     int a=st.first+d1[i],b=st.second+d2[i],c=dist[st.first][st.second],d=arr[st.first][st.second];
     test(a,b,c,d);
   }
  q.pop();
 } 
 if(dist[finX][finY]!=0)mn=min(mn,dist[finX][finY]);
}
  cout << mn << endl;
}