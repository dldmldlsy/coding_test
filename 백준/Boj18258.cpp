//���� 18258��
//�ܰ躰 ť
//ť2-correct!

//�ð��ʰ�-> \n!!
#include<iostream>
#include<queue>
using namespace std;
int main() {
	int n;
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;
	string oper;
	queue<int> q;
	while (n--) {
		cin >> oper; int x;
		if (oper == "push") {
			cin >> x;
			q.push(x);
		}
		else if (oper == "pop") {
			if (q.empty()) cout << -1 << "\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (oper == "size") {
			cout << q.size() << "\n";
		}
		else if (oper == "empty") {
			cout << q.empty() << "\n";
		}
		else if (oper == "front") {
			if (q.empty()) cout << -1 <<"\n";
			else cout << q.front() <<"\n";
		}
		else if (oper == "back") {
			if (q.empty()) cout << -1 <<"\n";
			else	cout << q.back() <<"\n";
		}
	}
}