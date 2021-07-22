//백준 1427
//단계별 - 정렬
//소트인사이드 (배열정렬)

// 두가지 방법으로 풂. 1) 숫자로 바꿔서 정렬한뒤에 거꾸로 출력, 2) 문자를 정렬해서 거꾸로 출력.
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	string s;
	cin >> s;
	//vector<int>v;
	//int num = 0;
	//for (int i = 0; i < s.size(); i++) {
	//	num = s.at(i) - '0';
	//	v.push_back(num);
	//}
	//sort(v.begin(), v.end());
	sort(s.begin(), s.end());
	for (int i = s.size() - 1; i >= 0; i--) {
		cout << s.at(i);
	}
}