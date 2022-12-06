
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

signed main(){
    int mx=-1e12;
    int ans=0;
    // key observation is that positive initial y velocities can go upto the target area's lowest y value which is -146 (the positive and negative values cancel out to 0)
    for(int i=1; i<=158; i++){
        for(int j=147; j>=-147; j--){
            int initX=i,initY=j,ok=0,posX=0,posY=0,high=0;
            for(int z=0; z<=1000; z++){
              posX+=initX; posY+=initY;
              if(initX>0)initX--;
              initY--;
              high=max(high,posY);
              if(102<=posX&&posX<=157&&-90>=posY&&posY>=-146){ans++;break;}
            }
        }
     }
     cout << ans << endl;
 }