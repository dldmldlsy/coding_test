//백준 8958번
//단계별 배열- ox퀴즈 - correct!

//못풀줄알았는데 한번에 풀었다:)
#include<iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	string oper;
	while (t--) {
		cin >> oper;
		int len = oper.length();
		int* a = new int[len];
		if (oper.at(0) == 'O') a[0] = 1; else a[0] = 0;
		for (int i = 1; i < len; i++) {
			if (oper.at(i)=='O') a[i] = a[i - 1] + 1;
			else a[i] = 0;
		}
		int sum = 0;
		for (int i = 0; i < len; i++) {
			sum += a[i];
		}
		cout << sum << endl;
	}
}