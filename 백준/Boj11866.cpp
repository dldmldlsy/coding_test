//���� 11866�� 21/ 7 /10
//�ܰ躰 - ť, ��
// �似Ǫ�� ���� 0 

//�ڷᱸ����ﶧ�� ����� �� �˾Ҵµ� ���� Ǫ�ϱ� ����
#include<iostream>
#include<queue>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	queue<int> q;
	for (int i = 1; i <= n; i++)
		q.push(i); 
	int re = k - 1;
	while (re--) {
		int f = q.front(); q.pop(); 
		q.push(f); 
	}
	cout << "<" << q.front();
	q.pop(); re = k - 1;
	while (!q.empty()) {
		cout << ", ";
		while (re--) {
			int f = q.front();
			q.pop();
			q.push(f);
		}
		cout << q.front();
		q.pop();
		re = k - 1;
	}
	cout << ">";

}