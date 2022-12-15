#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <algorithm>
#include "stdio.h"
#include <set>
#include <cmath>
#define int long long
#define mp make_pair
using namespace std;

int x1,x2,yE1,y2,ans=0;
vector<pair<int,int> >v,v2;
vector<int> tot;
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
     v.push_back(mp(x1,yE1)), v2.push_back(mp(x2,y2)); 
     tot.push_back(abs(x1-x2)+abs(yE1-y2)); // 1972741 max distance between each pair.
    }
   }
 file.close();
  for(int i=0; i<=4e6; i++){
    vector<pair<int,int> >check;
    for(int j=0; j<28; j++){
      int dist=abs(i-v[j].second);
      int need=tot[j]-dist;
      if(need<0) continue; 
      int mn=v[j].first-need,mx=v[j].first+need;
      mn=max(mn,(int)0); mx=min(mx,(int)4e6); // I have int for long long so dont confuse it lol
      check.push_back(mp(mn,mx));
    }
    for(int z=0; z<28; z++){
      if(v[z].second==i) check.push_back(mp(v[z].first,v[z].first));
      if(v2[z].second==i) check.push_back(mp(v2[z].first,v2[z].first));
    }
    sort(check.begin(),check.end());
    int ok=0,mxr=-1;
    for(int z=0; z<check.size()-1; z++){
      mxr=max(mxr,check[z].second);
      if(check[z+1].first-check[z].second==2&&check[z+1].first-1>mxr){
        int print=(check[z+1].first-1)*4e6+i;
        cout << print << endl; 
        ok=1; break;
      }
    }
    if(ok==1)break;
  }
}