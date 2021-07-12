//백준 11720번 21/7/12
//단계별 문자열
//숫자의 합 - correct!

//문자열에서 at을 이용하여 한문자씩 분리하고 '0'을 빼줘서 숫자로 바꾸는 거!
#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	char c; 
	int d; int sum = 0;
	for (int i = 0; i < n;i++) {
		c=s.at(i);
		d = c - '0';
		sum += d;
	}
	cout << sum;

}