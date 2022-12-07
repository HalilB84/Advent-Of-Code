#include <iostream>
#include <fstream>
#include <vector>
#include <string>


using namespace std;

int main() {
	vector<int> v;
	 ifstream file("d1.txt");
	if(file.is_open()) {
		string line;
		while(getline(file, line)) {
			v.push_back(stoi(line));
		}
	}
	file.close(); 
    //part 1
	int ans=0;
    for(int i=1; i<v.size(); i++){
		if(v[i]>v[i-1]) ans++;
	}
	cout << ans << endl;

	//part 2
	ans=0;
	for(int i=3; i<v.size(); i++){
		if(v[i]+v[i-1]+v[i-2] > v[i-1] + v[i-2] + v[i-3]) ans++;
	}
	cout << ans << endl;
	
}
