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

signed main(){
    ifstream file("d13.txt");
    string s;
    int x1,x2;
    int sum=0;
    if (file.is_open()){
     for(int i=0; i<1017; i++){
        string n="";
        file >> s;
        for(int j=0; j<s.size(); j++){
         if(s[j]==','){x1=stoi(n);n="";continue;}
         n+=s[j];
         if(j==s.size()-1)x2=stoi(n);
        }
        a[x1][x2]=1;
        sum++;
     }
    }
    file.close();
for(int j=0; j<=2000; j++){
    int inc=656;
    for(int i=654; i>=0; i--){
      if(a[i][j]==1&&a[inc][j]==1)sum--;
      inc++;
    }
 }
 cout << sum << endl;
}