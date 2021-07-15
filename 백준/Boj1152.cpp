//백준 1152번
//단계별 문자열
//단어의 개수 - correct!
//공백하나만 입력된 케이스 생각못해서 오래걸림!
#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	getline(cin, s);
	int n = s.length(); 
	int d; int count = 0;
	for (int i = 0; i < n; i++) {
		d = s.at(i);
		if (n == 1 &&d==32)
		{
			cout << "0"; return 0;
		}

		if (d == 32) {
			if (i == 0 || i == (n - 1))
				continue;
			else 
				count++;
		}
	}
	if (s.empty()) cout << "0";
	else cout << count+1;
	return 0; 
}