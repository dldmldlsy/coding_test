//백준 10814번 
//단계별 - 정렬
//나이순정렬 - correct! 
#include<iostream>
#include<vector>
#include<algorithm>// sort
using namespace std;
bool cmp(pair<pair<int,string>, int> a, pair<pair<int,string>, int> b) {
	if (a.first.first == b.first.first) return a.second < b.second;
	return a.first.first < b.first.first; 
}
int main() {
	int n; //회원수 
	cin >> n;
	vector<pair<pair<int,string>, int>> v; //나이,이름 ,  가입순
	int age;//나이
	string name; //이름 

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