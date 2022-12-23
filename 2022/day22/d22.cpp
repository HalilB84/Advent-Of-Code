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

pair<int,int> rowSt[300],rowEnd[300];
pair<int,int> colSt[300],colEnd[300];


// goes to 149 (len 150)
signed main(){
string s,turns;
ifstream file("d22.txt"); 
if(file.is_open()){
 for(int i=0; i<200; i++){
    getline(file,s);
    a[i]=s;
    for(int j=0; j<500; j++) a[i]+=" ";
 }
 getline(file,s); getline(file,s);
  turns=s;
}
file.close();
// rows
for(int i=0; i<200; i++){
    int ok=0;
    for(int j=0; j<150; j++){
     if(a[i][j]!=' '&&ok==0){rowSt[i].st=i;rowSt[i].nd=j;ok=1;} // 50
     if(a[i][j]!=' '){rowEnd[i].st=i;rowEnd[i].nd=j;}
    }
}
// column
for(int i=0; i<150; i++){
    int ok=0;
    for(int j=0; j<200; j++){
     if(a[j][i]!=' '&&ok==0){colSt[i].st=j;colSt[i].nd=i;ok=1;}
     if(a[j][i]!=' '){colEnd[i].st=j;colEnd[i].nd=i;}
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
int stX=50,stY=0,dir=0;
for(int i=0; i<order.size(); i++){
    if(order[i]==-1||order[i]==-2){
      if(order[i]==-1){dir--;if(dir==-1){dir=3;}}
      else{dir++; dir%=4;}
        continue;
    }
   for(int j=1; j<=order[i]; j++){
    if(dir==0){ //r
      if(rowEnd[stY].st==stY&&rowEnd[stY].nd==stX){
        if(a[rowSt[stY].st][rowSt[stY].nd]=='.'){stX=rowSt[stY].nd;}
      }
      else if(a[stY][stX+1]=='.')stX++;
    }
    if(dir==1){ //d
     if(colEnd[stX].st==stY&&colEnd[stX].nd==stX){
        if(a[colSt[stX].st][colSt[stX].nd]=='.'){stY=colSt[stX].st;}
      }
      else if(a[stY+1][stX]=='.')stY++;
    }
    if(dir==2){ //l
      if(rowSt[stY].st==stY&&rowSt[stY].nd==stX){
        if(a[rowEnd[stY].st][rowEnd[stY].nd]=='.'){stX=rowEnd[stY].nd;}
      }
      else if(a[stY][stX-1]=='.')stX--;
    }
    if(dir==3){ //u
      if(colSt[stX].st==stY&&colSt[stX].nd==stX){
        if(a[colEnd[stX].st][colEnd[stX].nd]=='.'){stY=colEnd[stX].st;}
      }
      else if(a[stY-1][stX]=='.')stY--;
    }
   }
}

stY++; stX++;
int ans=(1000*stY)+(4*stX)+(dir); // change these 
cout << ans << endl;
}