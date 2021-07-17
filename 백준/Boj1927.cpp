//백준 1927번
//단계별 - 우선순위 큐
//최소힙
//최대힙과 다르게 functional헤더의 greater를 이용하여 오름차순을 만들어야함
//\n도 꼭 해줘야 시간초과안남. 
#include<iostream>
#include<queue>
#include<functional>
using namespace std;
int main() {
	//시간초과 방지
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//우선순위큐 선언
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