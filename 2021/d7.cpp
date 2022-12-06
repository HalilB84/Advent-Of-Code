#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#define int long long
using namespace std;

int a[2005];
map<int,int> num;

signed main(){
    ifstream file("d7.txt");
    string s,n="";
    int ans=1e9,tot=0,inc=1;
    if (file.is_open()){
        file >> s;
    }
    file.close();
    for(int i=0; i<s.size(); i++){
      if(s[i]==','){num[stoi(n)]++; n="";} 
      else n+=s[i];
   }

   for(int i=2000; i>=1; i--){
     tot=num[i]; inc=1;
     map<int,int> l;
     for(int j=i-1; j>=0; j--){
        a[j]+=tot*inc+l[j+1];
        l[j]+=tot*inc+l[j+1];
        inc++;
     }
   }

   for(int i=0; i<2000; i++){
     tot=num[i]; inc=1;
      map<int,int> l;
     for(int j=i+1; j<=2000; j++){
        a[j]+=tot*inc+l[j-1];
        l[j]=tot*inc+l[j-1];
        inc++;
     }
   }
   for(int i=0; i<=2000; i++){
     ans=min(ans,a[i]);
   }
   cout << ans << endl;
}

