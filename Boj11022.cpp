//백준 11022번
//단계별 for문
//A+B-8
#include<iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	int a, b, c;
	for (int i = 1; i <= t; i++) {
		cin >> a >> b;
		cout << "Case #" << i << ": " << a << " + " << b << " = " << a + b << "\n";
	}
}