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
    ifstream file("d3.txt");
    string s,s1,s2;
    int sum=0;
    if (file.is_open()){
   while(file >> s >> s1 >> s2){
    map<char,int>m,m2;
    for(int i=0; i<s.size(); i++)m[s[i]]=1; 
    for(int i=0; i<s1.size(); i++) m2[s1[i]]=1;
    for(int i=0; i<s2.size(); i++){
    if(m2[s2[i]]==1&&m[s2[i]]==1){
        if(isupper(s2[i])){sum+=s2[i]-'A'+27;break;}
        else {sum+=s2[i]-'a'+1; break;}
     }
    }
   }
  }
    file.close();
    cout << sum << endl;
}