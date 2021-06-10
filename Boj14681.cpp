#include<iostream>
using namespace std;
int main() {
	int x, y;
	cin >> x >> y;
	int p;
	if (x > 0 && y > 0) {
		p = 1;
	}
	else if (x < 0 && y>0) {
		p = 2;
	}
	else if (x < 0 && y < 0) {
		p = 3;
	}
	else {
		p = 4;
	}
	cout << p << endl;
}