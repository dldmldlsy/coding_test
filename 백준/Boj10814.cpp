//���� 10814�� 
//�ܰ躰 - ����
//���̼����� - correct! 
#include<iostream>
#include<vector>
#include<algorithm>// sort
using namespace std;
bool cmp(pair<pair<int,string>, int> a, pair<pair<int,string>, int> b) {
	if (a.first.first == b.first.first) return a.second < b.second;
	return a.first.first < b.first.first; 
}
int main() {
	int n; //ȸ���� 
	cin >> n;
	vector<pair<pair<int,string>, int>> v; //����,�̸� ,  ���Լ�
	int age;//����
	string name; //�̸� 

	for (int i = 0; i < n; i++) {
		cin >> age >> name;
		pair<int, string> tmp; 
		tmp.first = age; tmp.second = name; 
		v.push_back(make_pair(tmp, i)); 
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first.first << " " <<v[i].first.second<< "\n";
	}
}