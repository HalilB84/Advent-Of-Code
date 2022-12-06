#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#define int long long
using namespace std;

signed main(){
    ifstream file("d2.txt");
    string s;
    vector<int>v;int ans=0;
    if (file.is_open()){
        string s1, s2;
     while(file >> s1 >> s2){
       if(s1=="A"&&s2=="X")ans+=3;
       if(s1=="A"&&s2=="Y")ans+=4;
       if(s1=="A"&&s2=="Z")ans+=8;
       if(s1=="B"&&s2=="X")ans+=1;
       if(s1=="B"&&s2=="Y")ans+=5;
       if(s1=="B"&&s2=="Z")ans+=9;
       if(s1=="C"&&s2=="X")ans+=2;
       if(s1=="C"&&s2=="Y")ans+=6;
       if(s1=="C"&&s2=="Z")ans+=7;
    }   
 }
  file.close();
  cout << ans << endl;
}

