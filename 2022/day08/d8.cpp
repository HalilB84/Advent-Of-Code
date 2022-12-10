#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <stack>
#define int long long
#define mp make_pair
using namespace std;

int a[150][150];

signed main(){
 ifstream file("d8.txt");
 string s;
 int ans2=0;
 if (file.is_open()){  
    for(int i=0; i<99; i++){
        file >> s;
      for(int j=0; j<99; j++){
        a[i][j]=stoi(string(1,s[j]));
      }
    }
 }
 file.close();
 int ans=0,ok;
 int mx=-1;
 for(int i=0; i<99; i++){
    for(int j=0; j<99; j++){
        int high=1;
    if(i==0||i==98||j==0||j==98){ans++;continue;}
    int test=0;
     for(int z=j+1; z<99; z++){
        test++;
        if(a[i][z]>=a[i][j])break;
     }
     high*=test;test=0;
     for(int z=j-1; z>=0; z--){
       test++;
        if(a[i][z]>=a[i][j])break;
     }
     high*=test; test=0;
     for(int z=i+1; z<99; z++){
        test++;
        if(a[z][j]>=a[i][j])break;
     }
     high*=test; test=0;
     for(int z=i-1; z>=0; z--){
        test++;
        if(a[z][j]>=a[i][j])break;
     }
     high*=test;
    mx=max(mx,high);
    }
 }
 cout << mx << endl;
}
  