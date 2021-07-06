//백준 4949번
//단계별 스택
//균형잡힌 세상

#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main() {
	string oper;
	while (oper != ".") {
		getline(cin, oper);
		if (oper == ".") break;
		stack<int> s;
		bool bal = true;
		for (int i = 0; i < oper.length(); i++) {
			if (oper.at(i) == '.') break;
			if (oper.at(i) == '('||oper.at(i) == '[')
				s.push(oper.at(i));
			else if (oper.at(i) == ')') {
				if (s.empty()||s.top()!='(') { bal = false; break; }
				s.pop();
			}
			else if (oper.at(i) == ']') {
				if (s.empty()||s.top()!='[') { bal = false; break; }
				s.pop();
			}
		}
		if (!s.empty()) bal = false;
		if (bal)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}