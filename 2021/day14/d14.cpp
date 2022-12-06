
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

int init[28][28];
int fake[28][28];
int be[28][28];
int tot[28];
vector<int> v;

signed main(){
    ifstream file("d14.txt");
    string s,s2;
    char s3;
    for(int i=0; i<26; i++){for(int j=0; j<26; j++){be[i][j]=-1;}}
    if (file.is_open()){
        file >> s;
     for(int i=0; i<s.size()-1; i++){
      init[s[i]-'A'][s[i+1]-'A']++;
      tot[s[i]-'A']++;
     }
     tot[s[s.size()-1]-'A']++;
     while(file >> s >> s2 >> s3){
       be[s[0]-'A'][s[1]-'A']=s3-'A';
     }
    }
    file.close();

    for(int z=0; z<40; z++){
        for(int i=0; i<26; i++){for(int j=0; j<26; j++){fake[i][j]=0;}}
        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
              if(init[i][j]==0){continue;}
              if(be[i][j]==-1){fake[i][j]+=init[i][j]; continue;}
               tot[be[i][j]]+=init[i][j];
               fake[i][be[i][j]]+=init[i][j];
               fake[be[i][j]][j]+=init[i][j];
               init[i][j]=0;
            }
        }
        for(int i=0; i<26; i++){for(int j=0; j<26; j++){init[i][j]=fake[i][j];}}
    }
    for(int i=0; i<26; i++){
      if(tot[i]>0) v.push_back(tot[i]);
        }
    sort(v.begin(), v.end());
    cout << v[v.size()-1]-v[0] << endl;
}