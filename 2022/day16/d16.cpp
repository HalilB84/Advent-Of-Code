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

vector<string> test;
vector<int> noble;
vector<vector<int> >adj(705);
map<string,int> m;
int cost[705], dist[705][705], used[705], ans=-1;
queue<pair<int,int> > q;
int blocked[705];
int tot=0;

// bruh I litterally debuged this entire thing for 5 hours to fix one line
int check(int a, int mx){
  if(a>=30){
    tot++;
     ans=max(ans,mx);
 return 1;
  }
  return 0;
}


int dfs(int cur, int mint, int pre, vector<int> u){
  int addRate=0;
 if(check(mint,pre)==1){
   return 0;
 }
  for(int i=0; i<=700; i++) blocked[i]=0;
  for(int i=0; i<u.size(); i++){
    addRate+=cost[u[i]];
    blocked[u[i]]=1;
  }
  if(cur!=0){pre+=addRate; mint++;}
   u.push_back(cur); blocked[cur]=1;
  addRate+=cost[cur];
 for(int i=0; i<noble.size(); i++){
  if(blocked[noble[i]]==0){
    int fake=pre;
   if(mint+dist[cur][noble[i]]<=30)fake+=addRate*(dist[cur][noble[i]]);
   else fake+=addRate*(30-mint);
   int why=dfs(noble[i], mint+dist[cur][noble[i]], fake, u);
   } 
  } 
  return 0;
}

signed main(){
// parser begin here
  noble.push_back(0); // add AA manualy
int ind=0;
for(char i='A'; i<='Z'; i++){
  for(char j='A'; j<='Z'; j++){
   string act=""; act+=i; act+=j;
   m[act]=ind;
   ind++;
  }
}   
 string s,s2;
 ifstream file("d16.txt"); // needs to chnage and has extra Valve at the end
  if (file.is_open()){
    while(file >> s){
    if(s=="Valve"&&test.size()>=1){
       string t=test[4];
      int ok=0;
       if(t.size()==7){cost[m[test[1]]]=stoi(t.substr(5,s.size()-4)); if(stoi(t.substr(5,s.size()-4))>=1)ok=1;}
       if(t.size()==8){cost[m[test[1]]]=stoi(t.substr(5,s.size()-3)); if(stoi(t.substr(5,s.size()-3))>=1)ok=1;}
      if(ok==1){ noble.push_back(m[test[1]]);}
      for(int i=9; i<test.size(); i++){
        string add=""; add+=test[i][0]; add+=test[i][1];
        adj[m[test[1]]].push_back(m[add]);
      }
     test.clear();
   }
   test.push_back(s);
  }
 }
file.close();
// perser ends here.

// bfs starts here
for(int i=0; i<=677; i++){
  while(!q.empty()) q.pop();
  for(int j=0; j<=680; j++)used[j]=0;
  q.push(mp(i,0)); used[i]=1;
  while(!q.empty()){
    pair<int,int> n=q.front();
   for(auto y:adj[n.first]){
    if(used[y]==0){used[y]=1;dist[i][y]=n.second+1;q.push(mp(y,dist[i][y]));}
  }
    q.pop();
 }
}
// bfs ends here (for all pairs)

// actual part starts here || Heuristic algorithm
vector<int> u; 
int fin = dfs(0,0,0,u);
cout << ans << endl;
cout << tot << endl;
}