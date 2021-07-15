//백준 2908번
//단계별 문자열 
//상수-correct!

#include<iostream>
using namespace std;
int main() {
	string a, b;
	cin >> a >> b;
	int a_1 = a.at(0) - '0';
	int a_2 = a.at(1) - '0';
	int a_3 = a.at(2) - '0';
	int a_ = a_3 * 100 + a_2 * 10 + a_1;
	int b_1 = b.at(0) - '0';
	int b_2 = b.at(1) - '0';
	int b_3 = b.at(2) - '0';
	int b_ = b_3 * 100 + b_2 * 10 + b_1;
	if (a_ > b_)
		cout << a_;
	else cout << b_;
}