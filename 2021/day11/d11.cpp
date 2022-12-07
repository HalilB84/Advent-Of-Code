#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>
#define int long long
#define mp make_pair
using namespace std;

int a[20][20];
int d1[9]={0,0,1,1,1,-1,-1,-1};
int d2[9]={1,-1,0,1,-1,-1,1,0};

queue<pair<int,int> > q;
int used[11][11];
int ans=-1;
int tot=0;

void add(int i, int j){
  for(int z=0; z<=7; z++){
   if(0<=i+d1[z]&&+i+d1[z]<=9&&0<=j+d2[z]&&j+d2[z]<=9&&used[i+d1[z]][j+d2[z]]==0){
     a[i+d1[z]][j+d2[z]]++;
      if(a[i+d1[z]][j+d2[z]]>=10){
       used[i+d1[z]][j+d2[z]]=1;q.push(mp(i+d1[z],j+d2[z]));
        }
      }
    }
}

signed main(){
    ifstream file("d11.txt");
    string s;
    int ind=0;
    if (file.is_open()){
     while(file >> s){
        for(int i=0; i<s.size(); i++){
         a[ind][i]=stoi(string(1,s[i]));
        }
       ind++;
     }
    }
    file.close();
    int z=1;
    while(true){
        while(!q.empty()) q.pop();
        for(int i=0; i<=9; i++){
          for(int j=0; j<=9; j++){
            used[i][j]=0;
            a[i][j]++;
            if(a[i][j]>9){used[i][j]=1;q.push(mp(i,j));}
        }
        }
        while(!q.empty()){
           add(q.front().first,q.front().second);
           q.pop();
        }
        tot=0;
        for(int i=0; i<=9; i++){
          for(int j=0; j<=9; j++){
            if(a[i][j]>9){tot++;a[i][j]=0;}
          }
        }
        if(tot==100&&ans==-1){ans=z;break;}
        z++;
    
 }
    cout << ans << endl;  
}