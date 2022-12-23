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

string a[300];

pair<int,int> xSide[8]{
 {50,99},
 {100,149},
 {50,99},
 {50,99},
 {0,49},
 {0,49},
};

pair<int,int> ySide[8]{
 {0,49},
 {0,49},
 {50,99},
 {100,149},
 {100,149},
 {150,199},
};

map<pair<int ,int> ,int > pos,dirChange;
vector<vector<int> > adj(20000),sidesTop(8),sidesBottom(8),sidesLeft(8),sidesRight(8);
vector<vector<int> > goTop(20000),goBottom(20000),goLeft(20000),goRight(20000);

// have to check these

// add dir changes

void lookForFoldTop(int x){
if(x==1){for(int i=0; i<50; i++){goTop[sidesTop[1][i]].pb(sidesLeft[6][i]); dirChange[{sidesTop[1][i],3}]=0;}}// 1 top and 6 left dir?
if(x==2){for(int i=0; i<50; i++){goTop[sidesTop[2][i]].pb(sidesBottom[6][i]);dirChange[{sidesTop[2][i],3}]=3;}}// 
if(x==3){for(int i=0; i<50; i++){goTop[sidesTop[3][i]].pb(sidesBottom[1][i]);dirChange[{sidesTop[3][i],3}]=3;}}// 
if(x==4){for(int i=0; i<50; i++){goTop[sidesTop[4][i]].pb(sidesBottom[3][i]);dirChange[{sidesTop[4][i],3}]=3;}}// 
if(x==5){for(int i=0; i<50; i++){goTop[sidesTop[5][i]].pb(sidesLeft[3][i]);dirChange[{sidesTop[5][i],3}]=0;}}// 
if(x==6){for(int i=0; i<50; i++){goTop[sidesTop[6][i]].pb(sidesBottom[5][i]);dirChange[{sidesTop[6][i],3}]=3;}}// 

}

void lookForFoldBottom(int x){
if(x==1){for(int i=0; i<50; i++){goBottom[sidesBottom[1][i]].pb(sidesTop[3][i]);dirChange[{sidesBottom[1][i],1}]=1;}}// 
if(x==2){for(int i=0; i<50; i++){goBottom[sidesBottom[2][i]].pb(sidesRight[3][i]);dirChange[{sidesBottom[2][i],1}]=2;}}// 
if(x==3){for(int i=0; i<50; i++){goBottom[sidesBottom[3][i]].pb(sidesTop[4][i]);dirChange[{sidesBottom[3][i],1}]=1;}}// 
if(x==4){for(int i=0; i<50; i++){goBottom[sidesBottom[4][i]].pb(sidesRight[6][i]);dirChange[{sidesBottom[4][i],1}]=2;}}// 
if(x==5){for(int i=0; i<50; i++){goBottom[sidesBottom[5][i]].pb(sidesTop[6][i]);dirChange[{sidesBottom[5][i],1}]=1;}}// 
if(x==6){for(int i=0; i<50; i++){goBottom[sidesBottom[6][i]].pb(sidesTop[2][i]);dirChange[{sidesBottom[6][i],1}]=1;}}// 
  
}

void lookForFoldLeft(int x){
if(x==1){for(int i=0; i<50; i++){goLeft[sidesLeft[1][i]].pb(sidesLeft[5][49-i]);dirChange[{sidesLeft[1][i],2}]=0;}}// 
if(x==2){for(int i=0; i<50; i++){goLeft[sidesLeft[2][i]].pb(sidesRight[1][i]);dirChange[{sidesLeft[2][i],2}]=2;}}// 
if(x==3){for(int i=0; i<50; i++){goLeft[sidesLeft[3][i]].pb(sidesTop[5][i]);dirChange[{sidesLeft[3][i],2}]=1;}}// 
if(x==4){for(int i=0; i<50; i++){goLeft[sidesLeft[4][i]].pb(sidesRight[5][i]);dirChange[{sidesLeft[4][i],2}]=2;}}// 
if(x==5){for(int i=0; i<50; i++){goLeft[sidesLeft[5][i]].pb(sidesLeft[1][49-i]);dirChange[{sidesLeft[5][i],2}]=0;}}// 
if(x==6){for(int i=0; i<50; i++){goLeft[sidesLeft[6][i]].pb(sidesTop[1][i]);dirChange[{sidesLeft[6][i],2}]=1;}}// 
  
}

void lookForFoldRight(int x){
if(x==1){for(int i=0; i<50; i++){goRight[sidesRight[1][i]].pb(sidesLeft[2][i]);dirChange[{sidesRight[1][i],0}]=0;}}// 
if(x==2){for(int i=0; i<50; i++){goRight[sidesRight[2][i]].pb(sidesRight[4][49-i]);dirChange[{sidesRight[2][i],0}]=2;}}// 
if(x==3){for(int i=0; i<50; i++){goRight[sidesRight[3][i]].pb(sidesBottom[2][i]);dirChange[{sidesRight[3][i],0}]=3;}}// 
if(x==4){for(int i=0; i<50; i++){goRight[sidesRight[4][i]].pb(sidesRight[2][49-i]);dirChange[{sidesRight[4][i],0}]=2;}}// 
if(x==5){for(int i=0; i<50; i++){goRight[sidesRight[5][i]].pb(sidesLeft[4][i]);dirChange[{sidesRight[5][i],0}]=0;}}// 
if(x==6){for(int i=0; i<50; i++){goRight[sidesRight[6][i]].pb(sidesBottom[4][i]);dirChange[{sidesRight[6][i],0}]=3;}}// 
  
}


signed main(){

for(int i=0; i<20000; i++){
  for(int j=0; j<=5; j++){
    dirChange[{i,j}]=-1;
  }
}

string s,turns;
ifstream file("d22.txt"); 
if(file.is_open()){
 for(int i=0; i<200; i++){
    getline(file,s);
    a[i]=s;
  //  for(int j=0; j<500; j++) a[i]+=" ";
 }
 getline(file,s); getline(file,s);
  turns=s;
}
file.close();

int ind=0;
for(int i=1; i<=6; i++){
    for(int j=ySide[i-1].st; j<=ySide[i-1].nd; j++){
      for(int z=xSide[i-1].st; z<=xSide[i-1].nd; z++){
         // store all 4 sides for 6 faces
         if(j==ySide[i-1].st)sidesTop[i].pb(ind);
         if(j==ySide[i-1].nd) sidesBottom[i].pb(ind);
         if(z==xSide[i-1].st){sidesLeft[i].pb(ind);}
         if(z==xSide[i-1].nd){sidesRight[i].pb(ind);}
         pos[{j,z}]=ind;
        //cout << j << " " << z << " "<< pos[{j,z}]<<endl;
         adj[ind].pb(j); adj[ind].pb(z);  // y - x
        //adj[ind][0]=j; adj[ind][1]=z;
         ind++;
      }
    }
}
for(int i=1; i<=6; i++){
         lookForFoldTop(i);
         lookForFoldBottom(i);
         lookForFoldLeft(i);
         lookForFoldRight(i);
   for(int j=ySide[i-1].st; j<=ySide[i-1].nd; j++){
      for(int z=xSide[i-1].st; z<=xSide[i-1].nd; z++){
         int index=pos[{j,z}];
        // add extra 3 sides for rows and cols
         if(j==ySide[i-1].st){ //top
           if(z==xSide[i-1].st){goBottom[index].pb(pos[{j+1,z}]);goRight[index].pb(pos[{j,z+1}]);}
           else if(z==xSide[i-1].nd){goBottom[index].pb(pos[{j+1,z}]);goLeft[index].pb(pos[{j,z-1}]);}
           else{goBottom[index].pb(pos[{j+1,z}]);goLeft[index].pb(pos[{j,z-1}]);goRight[index].pb(pos[{j,z+1}]);}
          continue;
         }
         if(j==ySide[i-1].nd){ // bottom
           if(z==xSide[i-1].st){goTop[index].pb(pos[{j-1,z}]);goRight[index].pb(pos[{j,z+1}]);}
           else if(z==xSide[i-1].nd){goTop[index].pb(pos[{j-1,z}]);goLeft[index].pb(pos[{j,z-1}]);}
           else{goTop[index].pb(pos[{j-1,z}]);goLeft[index].pb(pos[{j,z-1}]);goRight[index].pb(pos[{j,z+1}]);}
          continue;
         }
         if(z==xSide[i-1].st){ // left
           if(j==ySide[i-1].st){goBottom[index].pb(pos[{j+1,z}]);goRight[index].pb(pos[{j,z+1}]);}
           else if(j==ySide[i-1].nd){goTop[index].pb(pos[{j-1,z}]);goRight[index].pb(pos[{j,z+1}]);}
           else{goBottom[index].pb(pos[{j+1,z}]);goTop[index].pb(pos[{j-1,z}]);goRight[index].pb(pos[{j,z+1}]);}
          continue;
         } 
         if(z==xSide[i-1].nd){ // right
           if(j==ySide[i-1].st){goBottom[index].pb(pos[{j+1,z}]);goLeft[index].pb(pos[{j,z-1}]);}
           else if(j==ySide[i-1].nd){goTop[index].pb(pos[{j-1,z}]);goLeft[index].pb(pos[{j,z-1}]);}
           else{goBottom[index].pb(pos[{j+1,z}]);goTop[index].pb(pos[{j-1,z}]);goLeft[index].pb(pos[{j,z-1}]);}
          continue;
         } 
         goTop[index].pb(pos[{j-1,z}]);
         goBottom[index].pb(pos[{j+1,z}]);
         goLeft[index].pb(pos[{j,z-1}]);
         goRight[index].pb(pos[{j,z+1}]);
    }
  }
}
string n="";
vector<int> order; // -1 for L -2 to R
for(int i=0; i<turns.size(); i++){
 if(turns[i]=='R'||turns[i]=='L'){
  order.pb(stoi(n)); n=" "; 
  if(turns[i]=='R') order.pb(-2);
  else order.pb(-1);
  continue;
  }
 n+=turns[i];
if(i==turns.size()-1){order.pb(stoi(n));}
}

// actual traversing happens here
int stX=50,stY=0,dir=0,init=0;
for(int i=0; i<order.size(); i++){
    if(order[i]==-1||order[i]==-2){
      if(order[i]==-1){dir--;if(dir==-1){dir=3;}}
      else{dir++; dir%=4;}
        continue;
    }
   // cout << i << " " << init << " "<< dir <<endl;
for(int j=1; j<=order[i]; j++){
  if(dir==0){ //r
   int next=goRight[init][0];
   if(a[adj[next][0]][adj[next][1]]=='.'){
    if(dirChange[{init,0}]!=-1){dir=dirChange[{init,0}];}
    init=next;
   }
    continue;
  }
  
  if(dir==1){//d
   int next=goBottom[init][0];
   if(a[adj[next][0]][adj[next][1]]=='.'){
    if(dirChange[{init,1}]!=-1){ dir=dirChange[{init,1}];}
    init=next;
   }
    continue;
  }
  if(dir==2){//l
   int next=goLeft[init][0];
   if(a[adj[next][0]][adj[next][1]]=='.'){
    if(dirChange[{init,2}]!=-1){ dir=dirChange[{init,2}];}
    init=next;
      }
    continue;
   }
  
  if(dir==3){//u
   int next=goTop[init][0];
   if(a[adj[next][0]][adj[next][1]]=='.'){
    if(dirChange[{init,3}]!=-1){dir=dirChange[{init,3}];}
    init=next;
    }
      continue;
    }
  }
}
 cout << init << endl;
int ans=(adj[init][0]+1)*1000+(adj[init][1]+1)*4+dir;
  cout << ans << endl;
}