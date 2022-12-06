#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#define int long long
using namespace std;

signed main(){
    ifstream file("d1.txt");
    string s;
    vector<int>v;
    if (file.is_open()){
        int sum=0;
     while(getline(file,s)){
        if(s==""){v.push_back(sum); sum=0;}
        else sum+=stoi(s);
    }   
      sort(v.rbegin(),v.rend());
      cout << v[0] << endl;
      // part 2
      cout << v[0]+v[1]+v[2];
 }
  file.close();
}

