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

int a[3000][3000];
int b[3000][3000];
signed main(){
    ifstream file("d13.txt");
    string s;
    int x1,x2;
    int sum=0;
    if (file.is_open()){
     for(int z=0; z<18; z++){
        string n="";
        file >> s;
        for(int j=0; j<s.size(); j++){
         if(s[j]==','){x1=stoi(n);n="";continue;}
         n+=s[j];
         if(j==s.size()-1)x2=stoi(n);
        }
        a[x1][x2]=1; sum++;
     }
     
     for(int z=0; z<1; z++){
      sum=0;
      string n="";
      file >> s >> s >> s;
      int ok,f;
      if(s[0]=='y') ok=0;
      else ok=1;
      for(int j=2; j<s.size(); j++)n+=s[j];
       f=stoi(n);   
       if(ok==1){
       
      }
      else{
     
       } 
      }
  }
  file.close();

  ofstream myfile;
  myfile.open ("output.txt");
  
  int cnt=0;
  for(int i=0; i<2000; i++){
    for(int j=0; j<2000; j++){
      if(a[i][j]==1)cnt++;
      myfile << a[i][j];
    }
    myfile << endl;
  } 
  myfile.close(); 
  cout << cnt << endl;
}