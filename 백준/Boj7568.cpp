//백준 7568번
//단계별 - 브루트포스
//덩치- correct!
#include<iostream>
#include<vector>
using namespace std; 
int main() {
	int n; 
	cin >> n;  int x, y;
	vector<pair<pair<int,int>,int>> v; 
	while (n--) {
		cin >> x >> y;
		v.push_back(make_pair(make_pair(x,y), 1));
	}
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if (j == i) continue;
			if (v[i].first.first < v[j].first.first && v[i].first.second < v[j].first.second)
				v[i].second++;

		}
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << " ";
	}
	
}