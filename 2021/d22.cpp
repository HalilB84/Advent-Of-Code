
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

int a[105][105][105];

signed main(){
    ifstream file("d22.txt");
    string s,s2,n="";
    int ans=0;
    if (file.is_open()){
        int x1,x2,y1,y2,z1,z2;
    while(file >> s >> s2){
       for(int i=0; i<s2.size(); i++){
        

       }
           
   x1+=50,x2+=50;
   y1+=50,y2+=50;
   z1+=50,z2+=50;
   if(x2<0||100<x1)continue;
   if(y2<0||100<y1)continue;
   if(z2<0||100<z1)continue;
    
    if(s=="on"){
        for(int i=x1; i<=x2; i++){
            for(int j=y1; j<=y2; j++){
                for(int z=z1; z<=z2; z++){
                 if(a[i][j][z]==0){a[i][j][z]=1; ans++;}
              }
            }
          }}
    else{
        for(int i=x1; i<=x2; i++){
            for(int j=y1; j<=y2; j++){
                for(int z=z1; z<=z2; z++){
                 if(a[i][j][z]==1){a[i][j][z]=0; ans--;}
              }
            }
          }
          }
        }
    }
    file.close();
    cout << ans << endl;
 }