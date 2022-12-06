#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#define int long long
using namespace std;
long long a[10];
//long long b[10];
signed main(){
    ifstream file("d6.txt");
    string s;
    if (file.is_open()){
        file >> s;
    }
    file.close();
    for(int i=0; i<s.size(); i++){
        if(i%2==0)a[stoi(string(1,s[i]))]++;
    }
    for(int i=1; i<=80; i++){ // 256 for part 2;
        map<long long,long long > b;
        for(int j=0; j<=8; j++){
            if(j==0){b[6]+=a[0];b[8]+=a[0];}
            else b[j-1]+=a[j];
        }
        for(int j=0; j<=8; j++){
            a[j]=b[j];
        }
    }
    long long ans=0;
    for(int j=0; j<=8; j++){
            ans+=a[j];
        }
        cout << ans << endl;
}

