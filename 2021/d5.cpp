#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#define int long long
using namespace std;
int place[2002][2002];

signed main(){
    ifstream file("d5.txt");
     string s1,s2,s3,n="";
     int tot=0,inc=0;
    if (file.is_open()){
        while(file >> s1 >> s2 >> s3){
         int x1,x2,y1,y2;
         for(int i=0; i<s1.size(); i++){
           if(s1[i]==','){ x1=stoi(n); n=""; continue;}
            n+=s1[i];
            if(i==s1.size()-1){ y1=stoi(n); n="";}

         }
        n="";
        for(int i=0; i<s3.size(); i++){
           if(s3[i]==','){ x2=stoi(n); n=""; continue;}
            n+=s3[i];
            if(i==s3.size()-1){ y2=stoi(n); n="";}

         }
         if(x1==x2) for(int i=min(y1,y2); i<=max(y1,y2); i++) place[x1][i]++;
         else if(y1==y2) for(int i=min(x1,x2); i<=max(x1,x2); i++) place[i][y1]++;
         // part 2 after this
         else if(y2>y1&&x2>x1) for(int i=x1; i<=x2; i++){place[i][y1+inc]++; inc++;}
         else if(y2>y1&&x2<x1) for(int i=x2; i<=x1; i++){place[i][y2-inc]++; inc++;}
         else if(y2<y1&&x2>x1) for(int i=x1; i<=x2; i++){place[i][y1-inc]++; inc++;}
         else if(y2<y1&&x2<x1) for(int i=x2; i<=x1; i++){place[i][y2+inc]++; inc++;}
         inc=0;

        }
    }
    file.close();
    int ans=0;
    for(int i=0; i<=2000; i++){
        for(int j=0; j<=2000; j++){
            if(place[i][j]>=2) ans++;
        }
    }
    cout << ans << endl;
}

