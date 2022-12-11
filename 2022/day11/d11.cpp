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

// PLESE KEEP IN MIND THAT THIS CODE WORKS ON A MODIFIED INPUT FILE

int op[9];
int d[9];
int t[9];
int f[9];
string sign[9];
int tot[9];

vector<vector<int>> v
{
  {59, 65, 86, 56, 74, 57, 56},
  {63, 83, 50, 63, 56},
  {93, 79, 74, 55},
  {86, 61, 67, 88, 94, 69, 56, 91},
  {76, 50, 51},
  {77, 76},
  {74},
  {86, 85, 52, 86, 91, 95}
};

int test(int a, int b){
  if(sign[a]=="+"){
    return b+op[a];
  }
  if(sign[a]=="*"){
    if(op[a]==0) return b*b;
    else return b*op[a];
  }
}

signed main(){
int magic = 2*3*5*7*11*13*17*19; // all prime so lcm works
 ifstream file("d11.txt");
 string s1,s2,s3;
  int num,div,tr,fl;
 if (file.is_open()){
   for(int i=0; i<=7; i++){
     file >> s1 >> s2 >> s3;
     sign[i]=s2;
     if(s3=="old")op[i]=0;
     else op[i]=stoi(s3);
     file >> div >> tr >> fl;
     d[i]=div, t[i]=tr, f[i]=fl;
   }
 }
 file.close();
  for(int i=0; i<10000; i++){
   for(int z=0; z<=7; z++){
    for(int j=v[z].size()-1; j>=0; j--){
      int n=test(z,v[z][j]);
      n%=magic; // n=round(n/3); this line is the only change for part 1
      if(n%d[z]!=0)v[f[z]].push_back(n);
      else v[t[z]].push_back(n);
      v[z].pop_back();
      tot[z]++;
    }
   }
  }
 for(int i=0; i<=7; i++){
   cout << tot[i] << endl;
 }
}