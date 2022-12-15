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

vector<int> v;
int ar[1000][1000];;
int sX=500,sY=0,i=0,ans=0,mx=-1;

void draw(int a, int b, int c, int d){
  if(a==c){
    for(int i=min(b,d); i<=max(b,d); i++) ar[i][a]=1;
  }
  else{
    for(int i=min(a,c); i<=max(a,c); i++) ar[b][i]=1;
  }
}

int d(int a, int b){
 if(ar[a+1][b]==0){sY++;return 1;}
 if(ar[a+1][b-1]==0){sY++;sX--;return 1;}
 if(ar[a+1][b+1]==0){sY++;sX++;return 1;}
 return 0;
}

signed main(){
  string s;
 ifstream file("d14.txt");
 if (file.is_open()){
   while(getline(file,s)){
     v.clear();
     string n="";
     for(int i=0; i<s.size(); i++){
       if(s[i]!='>'&&s[i]!=' '&&s[i]!='-')n+=s[i];
       if(s[i]==','||i==s.size()-1){v.push_back(stoi(n)); n="";}
       if(s[i]==' '&&s[i-1]!='>'){v.push_back(stoi(n)); n="";}
        if(v.size()==4){ 
        mx=max(mx,v[1]);
        draw(v[0],v[1],v[2],v[3]); v.erase(v.begin(),v.begin()+2);}
     }
   }
}
cout << mx << endl; // max height is 153 so max will be 155
 file.close();
  while(true){
    sX=500,sY=0,i=0;
    if(sY==0&&sX==500&&ar[1][500]==1&&ar[1][501]==1&&ar[1][499]==1){ans++;break;}
    for(i=0; i<=600; i++){
     if(sY==154||d(sY,sX)==0){ar[sY][sX]=1;ans++;break;}
    }
  }
 cout << ans << endl;
}