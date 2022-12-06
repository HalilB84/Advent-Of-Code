#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#define int long long
using namespace std;

int c(string n){
 if(n=="("||n=="<"||n=="["||n=="{") return 1;
 return 0;
}

int match(string n, string n2){
    if(n=="("&&n2==")") return 1;
    if(n=="["&&n2=="]") return 1;
    if(n=="{"&&n2=="}") return 1;
    if(n=="<"&&n2==">") return 1;
 return 0;
}

int add(string n){
 if(n=="(") return 1;
 if(n=="[") return 2;
 if(n=="{") return 3;
 if(n=="<") return 4;
 return -1;
}

signed main(){
    ifstream file("d10.txt");
    string s;
    vector<int> v;
    int ans=0,ok=0;
    if (file.is_open()){
     while(file >> s){
        ans=0,ok=0;
        stack<string> st;
      for(int i=0; i<s.size(); i++){
       if(c(string(1,s[i]))==1) st.push(string(1,s[i]));
       else{
         if(match(st.top(), string(1,s[i]))==0){ok=1; break;}
        else  st.pop();
       }
      }
      while(!st.empty()){
        ans*=5;
        ans+=add(st.top());
        st.pop();
      }
      if(ok==0)v.push_back(ans);
    }
    file.close();
    sort(v.begin(), v.end());
    cout << v[v.size()/2] << endl;
 }
}
