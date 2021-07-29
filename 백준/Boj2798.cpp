//백준 2798번
//단계별 - 브루트포스
//블랙잭 - correct! 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, m; 
	cin >> n >> m; 
	int x; 
	vector<int> v; 
	vector<int> s; 
	while (n--) {
		cin >> x; 
		v.push_back(x);
	}
	int j, k = 0;
	n = v.size(); 
	for (int i = 0; i < n-2; i++) {
		for (int j = (i + 1) % n; j < n - 1; j++) {
			for (int k = (j + 1) % n; k < n; k++) {
				int sum = (v[i] + v[j] + v[k]);
				if (sum > m) continue;
				s.push_back(sum);
			}
		} 
	}
	sort(s.begin(), s.end()); //오름차순 정렬.
	cout << s.back(); 
}