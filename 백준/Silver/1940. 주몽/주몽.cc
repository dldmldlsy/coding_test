//백준 1940번 주몽
/*
* 갑옷을 만드는 재료들은 각각 고유번호가 있음. 
* 갑옷은 2개의 재료로 만듦. 2가지 재료의 고유번호를 합쳐서 m이 되면 갑옷이 만들어짐. ㅓ
* 자신이 만들고 있는 재료로 갑옷을 몇개나 만들 수 있을지?
* n개 재료, m -> 몇개나 갑옷을 만들 수 있을까? 
* 
* 재료 개수 n이 15000. m은 10000000 (천만)/ 시간제한 2초 
* O(nlogn) 도 가능 
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; 
	cin >> n >> m;

	vector<int> v(n); 
	for (int i = 0; i < n; i++) {
		cin >> v[i]; 
	}

	//정렬
	sort(v.begin(), v.end());
	int startIdx = 0; 
	int endIdx = n-1; 
	int cnt = 0; 
	int sum = 0; 

	
	while (startIdx<endIdx) {
		sum = v[startIdx] + v[endIdx];
		if (sum == m) {
			cnt++;
			startIdx++;
			endIdx--; 
		}
		else if (sum > m) {
			endIdx--; 
		}
		else { //sum<m
			startIdx++; 
		}
	}

	cout << cnt; 
}