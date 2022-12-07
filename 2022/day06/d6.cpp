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
 ifstream file("d6.txt");
 string s;
 int ans=0;
 if (file.is_open())file >> s;   
 file.close();
 for(int i=0; i<s.size(); i++){
    map<char,int> m;
    int ok=0;
    for(int j=i; j<i+14; j++){
     if(m[s[j]]==1){ok=1;break;}
     m[s[j]]=1;
    }
    if(ok==0){ans=i+14;break;}
 }
 cout << ans << endl;
}