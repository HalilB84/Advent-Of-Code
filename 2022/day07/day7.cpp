#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <stack>
#define int long long
#define mp make_pair
using namespace std;

signed main(){
 ifstream file("d7.txt");
 string s;
 int mx=100000;
 int ans=0,cur=0;
 vector<int>av,fin;

 if (file.is_open()){  
  for(int i=0; i<1015; i++){
    cur=0;
    file >> s;
    if(s=="$"){
        file >> s;
        if(s=="cd"){
            file >> s;
            if(s==".."){fin.push_back(av.back()); av.pop_back();}
            else {av.push_back(0);}
        }
    }
    else if(s=="dir"){file >> s;}
    else {cur+=stoi(s); 
    for(int j=0; j<av.size(); j++){
     av[j]+=cur;
    }
    file >> s;}    
  }
}
 file.close();
  fin.push_back(av.front());
  sort(fin.begin(),fin.end());
  int need=30000000-(70000000-fin.back());

 for(int i=0; i<fin.size(); i++){
    if(fin[i]>=need){ans+=fin[i];break;}
 }
 cout << ans << endl;
}
  