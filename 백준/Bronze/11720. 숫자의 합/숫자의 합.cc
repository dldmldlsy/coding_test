#include<iostream>
#include <vector> 
using namespace std; 
int main() {
	int n; 
	cin >> n; 
	int sum = 0;
	string str; 
	cin >> str;
	for(auto s: str) {
		sum += s - '0';
	}
	cout << sum; 
}