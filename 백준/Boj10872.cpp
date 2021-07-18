//백준 10872번
//단계별 - 재귀
//팩토리얼 -correct!

#include<iostream>
using namespace std;
int main() {
	int n; 
	cin >> n; 
	int mul = 1;
	if (n == 0) { cout << 1; return 0; }
	for (int i = 1; i <= n; i++) {
		mul *= i;
	}
	cout << mul;
}