#include<iostream>
#include<vector>
#include<algorithm> //sort
#include<cmath>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second; 
}
int main() {
	int n;  //n�� Ȧ��
	cin >> n;
	int avg, mid, mod, scp; //������, �߾Ӱ�, �ֺ�, ����
	vector<int> v; //n���� ���� ���� ����
	int temp; //�ӽ÷� ������ ����
	for (int i=0;i<n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end()); 
	double sum = v[0];
	for (int i = 1; i < v.size(); i++) {
		sum += v[i];
	}
	avg =sum / (double)n; 
	avg =(int) floor((sum/n) + 0.5);
	mid = v[n / 2]; 

	vector<pair<int, int>> vv; // �� ���� ����. 
	for (int i = 0; i < v.size(); i++) {
		if (vv.empty()) {
			vv.push_back(make_pair(v[i], 1)); continue;
		}
		if (vv.back().first == v[i]) {
			pair<int, int> tmp = vv.back();
			tmp.second++;
			vv.pop_back();
			vv.push_back(tmp); 
		}
		else {
			vv.push_back(make_pair(v[i], 1));
		}
	}
		
	sort(vv.begin(), vv.end(), cmp);
	if (vv.size() == 1 || vv[0].second != vv[1].second)
		mod = vv[0].first;
	else if (vv[0].second == vv[1].second)
		mod = vv[1].first;
	
	scp = v.back() - v.front();
	cout << avg << "\n" << mid << "\n" <<mod<<"\n"<< scp ;
	
}