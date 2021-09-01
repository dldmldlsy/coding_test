#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n; 
	vector<pair<int, int>> v; 
	int x;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> x; 
		v.push_back(make_pair(x,i+1));
	}
	sort(v.begin(), v.end()); //(-10,3) (-9, 5) (2,1) (4,2) (4,4)
	vector<pair<int, int>> vv; 
	vv.push_back({ 0,v[0].second });
	for (int i = 1; i < n; i++) {
		if (v[i].first == v[i - 1].first) {

		}
	}

}