//백준 2753번 21/6/22
//단계별 if문
//윤년
//correct! 

//문제 잘 읽기~

#include<iostream>
using namespace std;
int main() {
//윤년이면 1, 아니면 0
	int y;
	cin >> y;
	if (y % 4 == 0 && y % 100 != 0) {
		cout << "1" << endl;
	}
	else if (y % 400 == 0) {
		cout << "1" << endl;
	}
	else {
		cout << "0" << endl;
	}
}