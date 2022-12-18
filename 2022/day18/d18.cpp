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
#define pb push_back
#define st first
#define nd second
#define mp make_pair
using namespace std;

int a[55][55][55],b[50][50][50];
int d1[9]={1,-1,0,0,0,0},d2[9]={0,0,1,-1,0,0}, d3[9]={0,0,0,0,1,-1};
queue<pair<int,pair<int,int> > > q;
vector<int> vx,vy,vz;

signed main(){
int ans=0,ans2=0;
int x,y,z,ok=0;
ifstream file("d18.txt"); 
string s,n="";
if(file.is_open()){
  while(file >> s){
    ok=0;
   for(int i=0; i<s.size(); i++){
     if(s[i]!=',') n+=s[i];
     if(s[i]==','&&ok==1){y=stoi(n);n="";}
     if(s[i]==','&&ok==0){x=stoi(n);n="";ok=1;}
     if(i==s.size()-1){z=stoi(n);n="";}
   }
   a[x][y][z]=1;
   for(int i=0; i<6; i++){ //p1
    if(a[x+d1[i]][y+d2[i]][z+d3[i]]==1)ans--;
    else ans++;
   }
  }
}
file.close();

q.push(mp(0,mp(0,0)));
while(!q.empty()){
    x=q.front().st,y=q.front().nd.st,z=q.front().nd.nd;
    for(int i=0; i<6; i++){ 
    if(x+d1[i]>=0&&x+d1[i]<=48&&y+d2[i]>=0&&y+d2[i]<=48&&z+d3[i]>=0&&z+d3[i]<=48&&a[x+d1[i]][y+d2[i]][z+d3[i]]==0){
        a[x+d1[i]][y+d2[i]][z+d3[i]]=1;
        q.push(mp(x+d1[i],mp(y+d2[i],z+d3[i])));
  }
 }
 q.pop();
}
for(int i=0; i<49; i++){
  for(int j=0; j<49; j++){
   for(int k=0; k<49; k++){
     if(a[i][j][k]==0){vx.pb(i);vy.pb(j);vz.pb(k);}
  }
 }
}
for(int i=0; i<vx.size(); i++){
  b[vx[i]][vy[i]][vz[i]]=1;
   for(int j=0; j<6; j++){ 
    if(b[vx[i]+d1[j]][vy[i]+d2[j]][vz[i]+d3[j]])ans2--;
    else ans2++;
   }
}
cout << ans << endl;
cout << ans-ans2 << endl;

}