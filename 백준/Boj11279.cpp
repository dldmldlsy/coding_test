//백준 11279번
//단계별 - 우선순위큐
//최대힙 - correct!
#include<iostream>
#include<queue>
using namespace std;
int main() {
	//이 두줄 안하면 시간초과남 ㅠㅠ!
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