//���� 10828�� 21/7/5
//�ܰ躰 - ����
//���� - correct!

//���� �Ĳ��� �б�
#include<iostream>
#include<stack>
using namespace std;
int main() {
	int t; string oper;
	cin >> t;
	stack<int> s;
	for (int i = 0; i < t; i++) {

		int x;
		cin >> oper;
		if (oper == "push") {
			cin >> x;
			s.push(x);
		}
		else if (oper == "top") {
			if (s.empty()) cout << -1 << endl;
			else	cout << s.top() << endl;
		}
		else if (oper == "size") {
			cout << s.size() << endl;
		}
		else if (oper == "empty") {
			cout << s.empty() << endl;
		}
		else if (oper == "pop") {
			if (s.empty()) cout << -1 << endl;
			else {
				cout << s.top() << endl;
				s.pop();
			}
		}

	}
}