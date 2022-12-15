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

int x1,x2,yE1,y2,ans=0;
vector<pair<int,int> >v,v2;
vector<int> tot;
map<int,map<int,int> > m,mB;
signed main(){
  string s;
 ifstream file("d15.txt");
 if (file.is_open()){
   for(int i=0; i<28; i++){
     for(int j=0; j<10; j++){
      file >> s;
      if(j==2) x1=stoi(s.substr(2,s.size()-3));
      if(j==3) yE1=stoi(s.substr(2,s.size()-3));
      if(j==8) x2=stoi(s.substr(2,s.size()-3));
      if(j==9) y2=stoi(s.substr(2,s.size()-2));
     }
     v.push_back(mp(x1,yE1));
     tot.push_back(abs(x1-x2)+abs(yE1-y2));
     v2.push_back(mp(x2,y2));
     // 1972741 max distance between each pair.
    }
   }
 file.close();
  for(int i=-7e6; i<=7e6; i++){
    int floor=2000000,ok=1;
    for(int j=0; j<28; j++){
      if(v[j].first==i&&v[j].second==floor)ok=0;
      if(v2[j].first==i&&v2[j].second==floor)ok=0;
    }
    if(ok==0)continue;
    for(int j=0; j<28; j++){
      int dist=tot[j];
      if(abs(i-v[j].first)+abs(floor-v[j].second)<=dist){ans++; break;}
    }
  }
  cout << ans << endl;
}