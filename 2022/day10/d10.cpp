#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <set>
#define int long long
#define mp make_pair
using namespace std;

int a[10][50];

signed main(){
 string s;
  int num;
 ifstream file("d10.txt");
 int sum=0,cyc=0,x=0;
 if (file.is_open()){
   while(file >> s){
     if(s=="noop"){
      cyc++;
      int row = (cyc-1)/40, col = (cyc-1)%40;
      if(x<=col&&col<=x+2) a[row][col]=1;     
     }
     else{
       file >> num;
       for(int i=1; i<=2; i++){
         cyc++; 
         int row = (cyc-1)/40, col = (cyc-1)%40;
         if(x<=col&&col<=x+2) a[row][col]=1;
         if(i==2){x+=num;}
       }
     }
   }
 }
 file.close();
  for(int i=0; i<7; i++){
    for(int j=0; j<40; j++){
      if(a[i][j]==1)cout << a[i][j];
      else cout << " ";
    }
    cout << endl;
  }
}