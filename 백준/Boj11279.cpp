//���� 11279��
//�ܰ躰 - �켱����ť
//�ִ��� - correct!
#include<iostream>
#include<queue>
using namespace std;
int main() {
	//�� ���� ���ϸ� �ð��ʰ��� �Ф�!
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	priority_queue<int> pq; 
	int n;
	cin >> n; int x;
	while (n--) {
		cin >> x;
		if (x == 0) {
			if (pq.empty()) cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
			pq.push(x);
	}
}