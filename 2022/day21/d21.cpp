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
string a[3000][5];

int op(int num, int num2, string sign){
 if(sign=="+") return num+num2;
 if(sign=="-") return num-num2;
 if(sign=="*") return num*num2;
 if(sign=="/") return num/num2;
}

signed main(){
string s;
ifstream file("d21.txt"); 
map<string, int> m,val;
if(file.is_open()){
 for(int i=0; i<2397; i++){
   getline(file,s);
   if(s.size()==17){
    a[i][0]=s.substr(0,4);
    a[i][1]=s.substr(6,4);
    a[i][2]=s.substr(11,1);
    a[i][3]=s.substr(13,4);
   }
   else{
    a[i][0]=s.substr(0,4);
    m[a[i][0]]=1;
    val[a[i][0]]=stoi(s.substr(5,s.size()-5));
   }
 }
}
 file.close();
 while(m["root"]==0){
    for(int i=0; i<2397; i++){
     if(m[a[i][0]]==1) continue;
     if(m[a[i][1]]==1&&m[a[i][3]]==1){
      val[a[i][0]]=op(val[a[i][1]],val[a[i][3]],a[i][2]);
       m[a[i][0]]=1;
     }
   }
 }
 cout << val["root"] << endl;
 // root: zhfp + hghd
}