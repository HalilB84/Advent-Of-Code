#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#define int long long
#define pii = pair<int, int>;
using namespace std;

int a[200][200];
vector<vector<pair<int, int> > > adj;

void add(int i, int j){

if(i-1>=1) adj[i*j].push_back({(i-1)*j,a[i][j]});
if(j-1>=1) adj[i*j].push_back({(j-1)*i,a[i][j]});
if(i+1<=100) adj[i*j].push_back({(i+1)*j,a[i][j]});
if(j+1<=100) adj[i*j].push_back({(j+1)*i,a[i][j]});


}

signed main(){
    ifstream file("Ztest.txt");
    string s;
    int ind=0,tot=0;
    if (file.is_open()){
     while(file >> s){
        
     for(int i=0; i<s.size(); i++){
        a[ind+1][i+1]=stoi(string(1,s[i]));
     }
      ind++;
     }
    }
    file.close();
    int ans=0;
    for(int i=1; i<=100; i++){
        for(int j=1; j<=100; j++){
            add(i,j);
        }
    }
    
    vector<int>d(100000, 1e9);
    vector<int>p(100000, -1);

    d[1] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, 0});
    
    }
   // cout << d[10000]+a[100][100] << endl;
    
}

