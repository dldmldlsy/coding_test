#include<iostream>
#include<queue>
#include<functional> //�⺻ ���� less (��������), greater(��������)�Ϸ��� functional���Խ�������� 
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
int main(){
	int n; 
	cin >> n;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		pq.push(x);
	}
	int min1 = 0;
	int min2 = 0;
	int sum = 0;
	int res = 0;
	for (int i = 1; i < n; i++) {
		min1 = pq.top();
		pq.pop();
		min2 = pq.top();
		pq.pop();
		sum = min1 + min2;
		pq.push(sum);
		res += sum;
	}
	cout <<res << endl;
}