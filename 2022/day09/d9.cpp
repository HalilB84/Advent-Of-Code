#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include "stdio.h"
#include <set>
#define int long long
#define mp make_pair
using namespace std;

 int posX[12];
 int posY[12];
 int d1[9]={0,0,1,-1,1,-1,-1,1};
 int d2[9]={1,-1,0,0,-1,-1,1,1};
int test(int a, int b, int c, int d, int X, int Z){
  if(abs(a-c)<=X&&abs(b-d)<=Z) return 0;
  return 1;
}

signed main(){
 ifstream file("d9.txt");
 string s;
 int num;
 set<pair<int,int> > s2;
 s2.insert(mp(0,0));
 if (file.is_open()){
    for(int i=0; i<2000; i++){
        file >> s >> num;
       for(int j=0; j<num; j++){
         if(s=="U")posY[0]++;
         if(s=="D")posY[0]--; 
         if(s=="L")posX[0]--;
         if(s=="R")posX[0]++;
       for(int z=1; z<=9; z++){
        if(abs(posX[z-1]-posX[z])>1||abs(posY[z-1]-posY[z])>1){
            int x2=posX[z-1],y2=posY[z-1],x=posX[z],y=posY[z];
           for(int i=0; i<8; i++){
            if(i<=3){ if(test(x+d1[i],y+d2[i],x2,y2,abs(d1[i]),abs(d2[i]))==0){posX[z]+=d1[i]; posY[z]+=d2[i]; break;}}
            else{if(test(x+d1[i],y+d2[i],x2,y2,1,1)==0){posX[z]+=d1[i]; posY[z]+=d2[i]; break;}}
        }
       }
     s2.insert(mp(posX[9],posY[9]));
      }
    }}
    cout << s2.size()<< endl;
    file.close();
  } 
 }

 

