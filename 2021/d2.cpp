#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    // part 1
	ifstream file("d2.txt");
	if(file.is_open()) {
		int dep=0, hor=0, n;
		string dir;
		while(file >> dir >> n) {
			if(dir == "forward") {
				hor += n;
			} 
            if(dir == "up") {
				dep -= n;
			} 
            if(dir == "down") {
				dep += n;
			}
		}
		int ans = dep * hor;
		 cout << ans << endl;
	}
	file.close(); 
    // part 2
	ifstream file("d2.txt");
	if(file.is_open()) {
		int dep=0, hor=0, aim=0, n;
		string dir;
		while(file >> dir >> n) {
			if(dir == "forward") {
				hor += n;
                dep += aim*n;
			} 
            if(dir == "up") {
				aim -= n;
			} 
            if(dir == "down") {
				aim += n;
			}
		}
		 int ans = dep * hor;
		 cout << ans << endl;
	}
	file.close();
	
}
