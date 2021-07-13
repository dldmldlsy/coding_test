//백준 1157번
//단계별 - 문자열
//단어공부 -correct!

//가장 많이 쓰인 알파벳 출력, 여러개면 ?출력, 대소문자 구분x.
#include<iostream>
#include<vector>
using namespace std;
int main() {
	string s;
	cin >> s;
	int n = s.length();
	vector<int> v;
	int a = 'a';
	int z = 'z'; int A = 'A';
	int num = z - a + 1;
	for (int i = 0; i < num; i++) {
		v.push_back(0);
	}
	for (int i = a; i <= z; i++) {
		for (int j = 0; j < n; j++) {
			int s_asc = s.at(j);
			if (s_asc == i||s_asc==(i-32)) {
				v[i - 97]++;
			}
		}
	}
	int max = 0; int index = 0;
	for (int i = 0; i < v.size(); i++){
		if (max < v[i]){
			max = v[i]; index = i;
		}
	}
	bool same = false;
	for (int i = 0; i < v.size(); i++) {
		if (i == index) continue;
		if (max == v[i]) {
			same = true; break;
		}
	}
	char M = index + 65;
	if (same) cout << "?";
	else cout << M;
}