//���� 2751��
//�ܰ躰 - ����
//�� �����ϱ�2
#include<iostream>
#include<functional>
#include<queue>
using namespace std;
int main() {
	priority_queue<int, vector<int>, greater<int>> pq;
	int n;
	cin >> n; int x;
	int size = n;
	while (size--) {
		cin >> x; 
		pq.push(x);
	}
	while (n--) {
		cout << pq.top() << "\n";
		pq.pop();
	}
}