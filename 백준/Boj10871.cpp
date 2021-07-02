//백준 10871번 21/6/25
//단계별 -for문
//x보자 작은 수
//correct!
#include<iostream>
using namespace std;
int main() {
	int n, x,a;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a < x) cout << a << " ";
	}
}