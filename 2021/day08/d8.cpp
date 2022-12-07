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

char uni[8] = {'a','b','c','d','e','f','g'};

signed main(){
    ifstream file("d8.txt");
    int ans=0;
	if(file.is_open()){
        string s;
  for(int z=0; z<200; z++){
    char alp[8] = {'a','b','c','d','e','f','g'};
    string str[20];
    string look[20];
    map<string,int> m;
    m["abcefg"]=1; m["cf"]=2; m["acdeg"]=3;
    m["acdfg"]=4; m["bcdf"]=5; m["abdfg"]=6; 
    m["abdefg"]=7; m["acf"]=8; m["abcdefg"]=9; m["abcdfg"]=10;
    map<char,char>t;
    for(int i=0; i<11; i++){
        file >> s;
        str[i]=s;
    }
    for(int i=0; i<4; i++){
        file >> s; look[i]=s;
    }
    do {
     for(int i=0; i<7; i++){t[alp[i]]=uni[i];}
      int ok=0;
     for(int i=0; i<10; i++){
        string n="";
        for(int j=0; j<str[i].size(); j++){
          n+=t[str[i][j]];
        }
        sort(n.begin(),n.end());
        if(m[n]>=1)ok++;
     }
     if(ok==10){
        string test="";
        for(int i=0; i<4; i++){
             string fin="";
            for(int j=0; j<look[i].size(); j++){
             fin+=t[look[i][j]];
            }
            sort(fin.begin(),fin.end());
          test+=to_string(m[fin]-1);
        }
      ans+=stoi(test); break;
     }
   } while (next_permutation(alp, alp+7));
  }
}
    file.close(); 
    cout << ans << endl;
 }