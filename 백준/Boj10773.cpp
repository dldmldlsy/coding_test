//���� 107731�� 21/7/5
//�ܰ躰 - ����
//���� -correct!

#include<iostream>
#include<stack>
using namespace std;
int main() {
	int k; 
	cin >> k; 
	int x;
	stack<int> s;
	while (k--) {
		cin >> x;
		if (x == 0) {
			s.pop();
		}
		else {
			s.push(x);
		}
	}
	int sum = 0;
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}
	cout << sum << endl;
}