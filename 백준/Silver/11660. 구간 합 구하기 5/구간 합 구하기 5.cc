//백준 11660번 구간 합 구하기 5 
/*
* n: 1~1024, m: 1~100,000
* m 최대 100,000이고 시간제한 1초 -> O(n)에 풀어야 함.-> 구간 합 배열 이용하자.
*/
#include <iostream>
#include <vector>
using namespace std;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n + 1, vector<int>(n + 1, 0)); // 크기 n+1, 각 원소에 크기가 n+1이고 값이 0 인 벡터 할당
	vector<vector<int>> sum(n + 1, vector<int>(n + 1, 0)); // 구간 합 

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++) {
			cin >> v[i][j]; 

			//구간 합 계산
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + v[i][j]; 
		}
	}
	int x1, x2, y1, y2; 
	while (m--) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1]<<"\n";
	}
}