//백준 1978번
//단계별 -기본수학2
//소수찾기-correct!
#include<iostream>
using namespace std;
bool isPrimeNumber(int x);
int main() {
	int n; 
	cin >> n; int x; int count = 0;
	while (n--) {
		cin >> x;
		if (isPrimeNumber(x))
			count++;
	}
	cout << count;

}
bool isPrimeNumber(int x) {
	if (x <= 1)
		return false;
	int end = x / 2;
	for (int i = 2; i <= x / 2; i++) {
		if (x % i == 0)
			return false;
	}
	return true;
}
