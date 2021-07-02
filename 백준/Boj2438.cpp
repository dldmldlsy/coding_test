//백준 2438번 
//단계별 - for문 
//별찍기-1
//corret!

//아주 유명한 기초문제 (이중for문!)
#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int j = 1; j <= n; j++) {
		for (int i = 0; i < j; i++) {
			cout << "*";
		}
		cout << endl;
	}
}