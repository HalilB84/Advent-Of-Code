#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#define int long long
using namespace std;

int a[200][200];

int check(int i, int j){

if(i-1>=0&&a[i][j]>=a[i-1][j])  return 0;
if(j-1>=0&&a[i][j]>=a[i][j-1]) return 0;
if(i+1<=99&&a[i][j]>=a[i+1][j])  return 0; 
if(j+1<=99&&a[i][j]>=a[i][j+1])  return 0;

return 1;

}

signed main(){
    ifstream file("d9.txt");
    string s;
    int ind=0;
    if (file.is_open()){
     while(file >> s){
        
     for(int i=0; i<s.size(); i++){
        a[ind][i]=stoi(string(1,s[i]));
     }
      ind++;
     }
    }
    file.close();
    int ans=0;
    for(int i=0; i<100; i++){
        for(int j=0; j<s.size(); j++){
            if(check(i,j)==1) ans+=a[i][j]+1;
            
        }
    }
    cout << ans << endl;
    
}

