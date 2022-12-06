
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
    ifstream file("d4.txt");
    string s,n="";
    int ans=0,ans2=0,x1,x2,y1,y2,ok=0;
    if (file.is_open()){
    while(file >> s){
     ans2++,ok=0;
    for(int i=0; i<s.size(); i++){
      if(s[i]==','){x2=stoi(n); n="";continue;}
      if(s[i]=='-'&&ok==0){x1=stoi(n), n="",ok=1;continue;}
      if(s[i]=='-'&&ok==1){y1=stoi(n), n="",ok=1;continue;}
      n+=s[i];
      if(i==s.size()-1){y2=stoi(n); n="";}
    }
     if(x1<=y1&&y2<=x2)ans++;
     else if(y1<=x1&&x2<=y2)ans++;
    // part 2
    if(x2<y1)ans2--;
    else if(y2<x1)ans2--;
  }
}
 file.close();
 cout << ans << endl;
 cout << ans2 << endl;
}