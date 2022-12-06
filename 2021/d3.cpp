#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
int a[12];
int main(){
    // part 1
    ifstream file("d3.txt");
    if (file.is_open()){
        string s;
        int tot = 0;
        while (file >> s){
            // len = 12
            tot++;
            for (int i = 0; i <= 11; i++){
                a[i] += (s[i] == '1');
            }
        }
        string t1 = "", t2 = "";
        for (int i = 0; i <= 11; i++){
            if (tot - a[i] > tot / 2){
                t1 += "1", t2 += "0";
            }
            else{
                t1 += "0", t2 += "1";
            }
        }
        cout << t1 << " " << t2 << endl;
    }
    file.close(); 

   // part 2 
   // also did this part for both oxygen and carbon by changing ok factors (code for only one included)
   vector<string> v;
   ifstream file("d3.txt");
    if (file.is_open()){
        string s;
        int tot = 0;
        while (file >> s){
            tot++;
            v.push_back(s);
        }
        int fak=tot;
        char ok='0';
       for(int j=0; j<=11; j++){ 
          int tmp=0;
        for(int i=0; i<v.size(); i++){
           if(v[i][j]=='1') tmp++;
        }
        if(tmp>=(fak+1)/2){ok='0';}
        else {ok='1';}
        for(int k=v.size()-1; k>=0; k--){
         if(v[k][j]==ok) v.erase(v.begin()+k);
      } 
       fak=v.size();
        }
        cout << v[0] << endl;
    file.close();
   }
}
