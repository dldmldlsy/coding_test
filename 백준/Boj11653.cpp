//백준 11653번 
//기본 수학2- 소인수분해
#include<iostream>
using namespace std;
int main() {
	int n; 
	cin >> n;
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			cout << i << endl;
			n = n / i;
		}
	}
	if (n > 1)
		cout << n << endl;
}