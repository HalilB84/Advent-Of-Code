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

signed main(){
 ifstream file("d5.txt");
 string s1,s3,s5;
 vector<vector<char>>v;
int s2,s4,s6;
 if (file.is_open()){
    for(int i=0; i<10; i++){
      getline(file,s1);
      int ind=1;
      for(int j=1; j<s1.size(); j+=4){
       if(s1[j]!=' ') v[i][ind].push_back(s1[j]); 
       ind+=4;
      }
    }  getline(file,s1);  getline(file,s1);
    while(file >> s1 >> s2 >> s3 >> s4 >> s5 >> s6){
      vector<char>fake;
     for(int i=0; i<s2; i++){
        char add=v[s4-1][v[s4-1].size()-1-i];
       fake.push_back(add);
     }
      for(int i=fake.size()-1; i>=0; i--){
      v[s6-1].push_back(fake[i]);
       v[s4-1].pop_back();
        }
      }
    }
 file.close();
 for(int i=0; i<9; i++){
   cout <<v[i][v[i].size()-1];
 }
}