//백준 10809번
//단계별 - 문자열

//알파벳 찾기 - correct! 
#include<iostream>
using namespace std;
int main() {
	string alp;
	cin >> alp;
	int n = alp.length();
	int a = 'a'; //a의 아스키코드값
	int z = 'z'; int alp_asc; 
	for (int i = a; i <= z; i++) {
		bool isChar = false;
		for (int j = 0; j < n;j++) {
			alp_asc = alp.at(j);
			if (alp_asc == i) {
				isChar = true; //알파벳있음. 
				cout << j << " ";
				break;
			}
		}
		if (!isChar) cout << -1 << " ";
	}
	
	
}