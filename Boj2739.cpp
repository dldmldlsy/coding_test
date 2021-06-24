//백준 2739번
//단계별 for문
#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n; 
	for (int i = 1; i < 10; i++) {
		cout << n << " * " << i << " = " << n * i << endl;
	}
}