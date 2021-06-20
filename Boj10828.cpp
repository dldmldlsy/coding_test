#include<iostream>
#include<stack>
using namespace std;
int main() {
	int t; string oper;
	cin >> t;
	stack<int> s;
	for (int i = 0; i < t; i++) {

		int x;
		if (oper == "push") {
			cin >> x;
			s.push(x);
		}
		else if (oper == "top") {
			cout << s.top() << endl;
		}
		else if (oper == "empty") {
			cout << s.empty() << endl;
		}
		else if (oper == "pop") {
			s.pop();
		}
		else {
			cout<<"´Ù½Ã" << endl;
		}
	}
}