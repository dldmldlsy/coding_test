//백준 2588번 21/6/22
//알고리즘 단계별-입출력과사칙연산
//곱셈

#include<iostream>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	int b1, b2, b3;
	b1 = b / 100;
	b2 = (b - b1 * 100) / 10;
	b3 = (b - b1 * 100 - b2 * 10) ;
	cout << a * b3 << endl;
	cout << a * b2 << endl;
	cout << a * b1 << endl;
	cout << a * b << endl;
}