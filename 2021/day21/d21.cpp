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

// doesnt have part 2 now

signed main(){
    int pos1=7,pos2=4,pos1a=0,pos2a=0;
    int dice=0,time=0;
    int ans=0;
    for(int i=0; i<2000; i++){
        if(i%2==0){
        int n=0;
         for(int j=0; j<3; j++){dice++;if(dice>100){dice=1;}n+=dice;time++;}
         pos1+=(n%10);
         if(pos1>=11){pos1%=11;pos1++;}
         pos1a+=pos1;
         if(pos1a>=1000){ans=pos2a*time;break;}
        }
        else{
        int n=0;
         for(int j=0; j<3; j++){dice++;if(dice>100){dice=1;}n+=dice;time++;}
         pos2+=(n%10);
         if(pos2>=11){pos2%=11;pos2++;}
         pos2a+=pos2;
         if(pos2a>=1000){ans=pos1a*time;break;}
        }
    }
    cout << ans << endl;
 }