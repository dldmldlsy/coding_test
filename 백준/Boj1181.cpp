//백준 1181번
//단계별 정렬
//단어정렬 - correct! 

#include<iostream>
#include<vector>
#include<algorithm> //sort, unique
using namespace std;
bool cmp(pair<string, int> a, pair<string, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}
int main() {
	int n; 
	cin >> n; 
	string s; int len;
	vector<pair<string, int>> v;
	vector<string> vv; 
	while (n--) {
		cin >> s; 
		vv.push_back(s);
	}
	sort(vv.begin(), vv.end());
	vv.erase(unique(vv.begin(), vv.end()), vv.end());
	
	for(int i = 0; i < vv.size(); i++) {
		len = vv[i].length(); 
		v.push_back(make_pair(vv[i], len)); 
	}
	sort(v.begin(), v.end(), cmp);
	for(int i = 0; i < v.size(); i++) {
		cout << v[i].first << "\n";
	}
}
