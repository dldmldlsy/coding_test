//백준 11650번
//단계별 - 정렬
//좌표 정렬하기 -correct!
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n; 
	cin >> n;
	int x, y;
	vector<pair<int, int>> v;
	while (n--) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	sort(v.begin(), v.end()); 
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
}