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

int oreR, clayR, obsOreR, obsClayR, geoOreR, geoObsR,ans=0,mx=0;
int oreRobot, clayRobot, obsidianRobot, geodeRobot;
int tot=0;

// working on this still


// Heuristic again 

int dfs(int mint, int oreBot, int clayBot, int obsBot, int geoBot, vector<int> amount, int type){
  
   amount[0]+=oreBot;
   amount[1]+=clayBot;
   amount[2]+=obsBot;
   amount[3]+=geoBot;
  //if(amount[3]>=2)cout << amount[3] << " "<< mint << endl;
 if(type==0)oreBot++; 
  if(type==1)clayBot++; 
   if(type==2)obsBot++; 
 if(type==3)geoBot++; 

 int ok5=1,ok2=1,ok3=1,ok4=1;
   if(mint>=24){
   tot++;
    mx=max(mx,amount[3]);
    return 0;
   }
 if(1==1){
   ok5=0;
   if(amount[0]>=oreR){
   amount[0]-=oreR;  
   int a = dfs(mint+1, oreBot, clayBot, obsBot, geoBot, amount,0);
   amount[0]+=oreR; 
 }
   else int g = dfs(mint+1, oreBot, clayBot, obsBot, geoBot, amount,-1);
 }
 
 if(amount[0]>=geoOreR&&amount[2]>=geoObsR){
    ok2=0;
   amount[0]-=geoOreR; amount[2]-=geoObsR;
   int d = dfs(mint+1, oreBot, clayBot, obsBot, geoBot, amount,3);
   amount[0]+=geoOreR; amount[2]+=geoObsR; 
 }

 if(amount[0]>=obsOreR&&amount[1]>=obsClayR){
    ok3=0;
   amount[0]-=obsOreR; amount[1]-=obsClayR; 
   int c = dfs(mint+1, oreBot, clayBot, obsBot, geoBot, amount,2);
   amount[0]+=obsOreR; amount[1]+=obsClayR; 
 }
 
 if(amount[0]>=clayR){
  ok4=0;
   amount[0]-=clayR; 
   int b = dfs(mint+1, oreBot, clayBot, obsBot, geoBot, amount,1);
   amount[0]+=clayR;
 }
 mx=max(mx, amount[3]+geoBot);
  return 0;
}
signed main(){
ifstream file("test.txt"); 
int num=0;
string s;
if(file.is_open()){
  for(int i=1; i<=1; i++){
    for(int j=0; j<32; j++){
      if(j==6){file >> num; oreR=num;}
      else if(j==12){file >> num; clayR=num;}
      else if(j==18){file >> num; obsOreR=num;}
      else if(j==21){file >> num; obsClayR=num;}
      else if(j==27){file >> num; geoOreR=num;}
      else if(j==30){file >> num; geoObsR=num;}
      else {file >> s;}
    }
    vector<int> amount; amount.clear();
    amount.pb(0); amount.pb(0); amount.pb(0); amount.pb(0);
    // 0 ore - 1 clay - 2 obsidian - 3 geode
    mx=0;
   int p=dfs(1,1,0,0,0, amount,-1);
   ans+=i*mx;
   cout << 28*mx << endl;
  // cout << i*mx << endl;
  }
}
file.close();
cout << ans << endl;
cout << tot << endl;
}