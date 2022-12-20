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
// 0 for empty 1 for anything else
int arr[9][20000];
int stX,stY,maxH=0,condition=0,indx=0;

pair<int,int> leftSide[10]{
  {0,0},
  {0,2},
  {0,2},
  {0,3},
  {0,1},
};

pair<int,int> rightSide[10]{
  {3,3},
  {2,4},
  {1,3},
  {0,3},
  {2,3},
};

pair<int,int> downSide[10]{
  {0,3},
  {1,3},
  {3,5},
  {0,0},
  {1,2},
};

vector<vector<pair<int,int>>> tetris{
 {{0,0},{1,0},{2,0},{3,0}},
 {{0,2},{-1,1},{0,0},{1,1},{0,2},{0,1}},
 {{0,0},{2,1},{2,2},{2,0},{0,0},{1,0}},
 {{0,0},{0,1},{0,2},{0,3}},
 {{0,1},{0,0},{1,0},{1,1}},
};

void horizontal(int t, int d){
  int ok=0;
  if(d==1){
    for(int i=rightSide[t].st; i<=rightSide[t].nd; i++){
     int nX=stX+tetris[t][i].st,nY=stY+tetris[t][i].nd;
      nX+=d;
     if(nX<1||nX>7||arr[nX][nY]==1) ok=1;
    }
  }
   if(d==-1){
    for(int i=leftSide[t].st; i<=leftSide[t].nd; i++){
     int nX=stX+tetris[t][i].st,nY=stY+tetris[t][i].nd;
      nX+=d;
     if(nX<1||nX>7||arr[nX][nY]==1) ok=1;
    }
  }
  if(ok==0){stX+=d;}
}

void down(int t){
  int ok=0;
  for(int i=downSide[t].st; i<=downSide[t].nd; i++){
    int nX=stX+tetris[t][i].st,nY=stY+tetris[t][i].nd;
    nY--;
    if(nY<1||arr[nX][nY]==1) ok=1;
  }
  if(ok==0)stY--;
  else condition=1;
}

signed main(){
ifstream file("d17.txt"); 
string s;
if(file.is_open()){file >> s;}
file.close();
for(int i=0; i<20; i++){
   condition=0;
   stX=3,stY=maxH+4;
 int type=i%5;
 if(type==1) stX++;
  while(condition==0){
  int dir=(s[indx%s.size()]=='>'); // < means -1 and left ||| > means 1 and right
  if(dir==0){dir=-1;}
   horizontal(type,dir);
   down(type);
   indx++;
  }
  // add new rested block here
   for(int i=0; i<tetris[type].size(); i++){
    int neX=stX+tetris[type][i].st,neY=stY+tetris[type][i].nd;
     arr[neX][neY]=1;
  }
  
  for(int i=14000; i>=1; i--){ // new max height limit
   int ok=0;
   for(int j=1; j<=7; j++){
     if(arr[j][i]==1) ok=1;
    }
   if(ok==1){maxH=i; break;}
  }
 }
  for(int i=20; i>=0; i--){
    for(int j=0; j<9; j++){
      cout << arr[j][i];
    }
    cout << endl;
  }
  cout << maxH << endl;
}