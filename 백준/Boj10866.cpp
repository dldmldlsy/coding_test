//백준 10866번
//단계별 - 큐, 덱
//덱 -correct!

#include<iostream>
#include<deque>
using namespace std;
int main() {
	int n;
	cin >> n;
	string oper; int x;
	deque<int> d;
	while (n--) {
		cin >> oper;
		if (oper == "push_back") {
			cin >> x;
			d.push_back(x);
		}
		else if (oper == "push_front") {
			cin >> x;
			d.push_front(x);
		}
		else if (oper == "front") {
			if (d.empty()) cout << -1 << endl;
			else cout << d.front() << endl;
		}
		else if (oper == "back") {
			if (d.empty()) cout << -1 << endl;
			else cout << d.back() << endl;
		}
		else if (oper == "size")
			cout << d.size() << endl;
		else if (oper == "empty")
			cout << d.empty() << endl;
		else if (oper == "pop_front") {
			if (d.empty()) cout << -1 << endl;
			else { cout << d.front() << endl; d.pop_front(); }
		}
		else if (oper == "pop_back") {
			if (d.empty()) cout << -1 << endl;
			else { cout << d.back() << endl; d.pop_back(); }
		}
	}
}