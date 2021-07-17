//백준 2941번
//단계별 - 문자열
//크로아티아 알파벳

//for문안에서 중간에 맘대로 조건인자i를 바꾸면 조건을 만족시키는지 따로 체크해줘야함. 
#include<iostream>
using namespace std;
int main() {
	string s;
	cin >> s;
	int count = 0;
	for (int i = s.length() - 1; i >= 0; i--) {

		if (s.at(i) == '=') {
			i--;
			if (s.at(i) == 'c' || s.at(i) == 's') {
				count++; 
			}
			else if (s.at(i) == 'z') {
				if (i == 0) { count++; break; }
				i--;
				if (s.at(i) == 'd') {
					count++;
				}
			    else { 
					count++; i++; 
				}
			}
		}
		else if (s.at(i) == '-') {
			i--;
			if (s.at(i) == 'c' || s.at(i) == 'd') {
				count++;
			}
		}
		else if (s.at(i) == 'j') {
			if (i == 0) { count++; break; }

			i--;
			if (s.at(i) == 'l' || s.at(i) == 'n') {
				count++;
			}
			else {
				count++;  i++; 
			}
		}else {
			count++;
		}
	}
	cout << count;
}