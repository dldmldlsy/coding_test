//백준 5622번
//단계별 - 문자열 
//다이얼 -correct! 

#include<iostream>
using namespace std;
int main() {
	string s; 
	cin >> s; //단어가 주어짐. 
	int time = 0; int number=0;
	for (int i = 0; i < s.length(); i++) {
		int asc = s.at(i); //A=65
		if (65 <= asc&&asc <= 67) {
			number = 2;
		}
		else if (68 <= asc&&asc <= 70) {
			number = 3;
		}
		else if (71 <= asc && asc <= 73) {
			number = 4;
		}
		else if (74 <= asc && asc <= 76) {
			number = 5;
		}
		else if (77 <= asc && asc <= 79) {
			number = 6;
		}
		else if (80 <= asc && asc <= 83) {
			number = 7;
		}
		else if (84 <= asc && asc <= 86) {
			number = 8;
		}
		else if (87 <= asc&&asc <= 90) {
			number = 9;
		}
		time += (number + 1);
	}
	cout << time;
}