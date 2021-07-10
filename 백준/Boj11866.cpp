//백준 11866번 21/ 7 /10
//단계별 - 큐, 덱
// 요세푸스 문제 0 

//자료구조배울때는 어려운 줄 알았는데 지금 푸니까 쉽당
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