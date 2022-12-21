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

int ans=0;
vector<pair<int,int> > a;
vector<int> order;
signed main(){
ifstream file("d20.txt"); 
int num,ind=0;
if(file.is_open()){
 while(file>>num){
  a.pb(mp(num*811589153,ind));
  ind++;
 }
}
file.close();
for(int z=0; z<10; z++){
    int newindx;
 for(int i=0; i<5000; i++){
    int index,add,move,val;
    for(int j=0; j<5000; j++) if(a[j].second==i){index=j; add=a[j].second; move=a[j].first; val=a[j].first; break;}
    if(move>=0) newindx = (index+move)%4999;
    else{
    move=-(abs(move)%4999); 
    if(abs(move)<index){newindx = (index+move);}
    else{newindx=4999-(abs(move)-index);}
    }
    a.erase(a.begin()+index);
    a.insert(a.begin()+newindx,mp(val,add));
 }
}
int fin;
for(int i=0; i<5000; i++){
    if(a[i].first==0) fin=i;
}

ans+=a[(fin+1000)%5000].first; ans+=a[(fin+2000)%5000].first; ans+=a[(fin+3000)%5000].first;
cout << ans << endl;
}