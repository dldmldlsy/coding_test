//���� 11651��
//�ܰ躰 - ����
//��ǥ �����ϱ�2  - correct!

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(pair<int, int>a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}
int main(){
	int n; 
	cin >> n; 
	int x, y; 
	vector<pair<int, int>> v; 
	while (n--) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
}