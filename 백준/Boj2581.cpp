//백준 2581번
//단계별 -기본수학2
//소수 
#include<iostream>
#include<vector>
using namespace std;
bool isPrimeNumber(int x);
int main() {
	int m,n;
	cin >> m>>n; 
	vector<int> v;
	for (int i = m; i <= n;i++) {
		if (isPrimeNumber(i))
			v.push_back(i);
	}
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
	}
	if (v.empty()) cout << -1;
	else {
		cout << sum << endl;

		cout << v[0];
	}
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
