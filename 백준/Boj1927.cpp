//���� 1927��
//�ܰ躰 - �켱���� ť
//�ּ���
//�ִ����� �ٸ��� functional����� greater�� �̿��Ͽ� ���������� ��������
//\n�� �� ����� �ð��ʰ��ȳ�. 
#include<iostream>
#include<queue>
#include<functional>
using namespace std;
int main() {
	//�ð��ʰ� ����
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//�켱����ť ����
	priority_queue<int, vector<int>, greater<int> > pq; 
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
		else { pq.push(x); }

	}
}