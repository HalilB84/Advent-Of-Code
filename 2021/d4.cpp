#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int bingoX[600][500];
int bingoY[600][500];
int used[600][6][6]; // lesson learned always have some extra space when initilazing these
int num[600][6][6];
int last[600];

int check(int x, int just){
   int ok=0;
  for(int j=1; j<=5; j++){
    int tmp=0;
   for(int i=1; i<=5; i++){
      tmp+=used[x][i][j];
   }
   if(tmp==5)ok=1;
  }
  for(int i=1; i<=5; i++){
     int tmp=0;
   for(int j=1; j<=5; j++){
      tmp+=used[x][i][j];
   }
   if(tmp==5)ok=1;
  }
  if(ok==1){
   int ans=0;
    for(int i=1; i<=5; i++){
   for(int j=1; j<=5; j++){
      if(used[x][i][j]==0) ans+=num[x][i][j];
   }
  }
   last[x]=1;
   return ans*just;
  }
  return -1;
}

int main() {
   ifstream file("d4.txt");
    string s,n="";
    int tot=0;
    int reset=0,numb,i=1,j=1,ind=0;
    if (file.is_open()){
        file >> s;
        while(file >> numb){
         reset++;
         num[ind][i][j]= numb;
         bingoX[ind][numb] = i;
         bingoY[ind][numb] = j;
          j++;
      if(j==6){j=1; i++;}
      if(reset==25){i=1,j=1;ind++; reset=0;tot++;}
        }
    }
    file.close();

   vector<int> num;
   // parse the input here
   // keep in mind that I added a extra comma at the end in the txt file to make this work
   for(int i=0; i<s.size(); i++){
      if(s[i]==','){num.push_back(stoi(n));n="";} 
      else n+=s[i];
   }

   for(int i=0; i<num.size(); i++){
     for(int j=0; j<tot; j++){
      if(last[j]==1)continue;
       used[j][bingoX[j][num[i]]][bingoY[j][num[i]]]=1;
       int fin = check(j,num[i]);
       if(fin!=-1){cout << fin << endl; }
     }
   }
	
}