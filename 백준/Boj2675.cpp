//���� 2675��
//�ܰ躰 -���ڿ� 
//���ڿ� �ݺ� -correct!
#include<iostream>
using namespace std;
int main() {
	int t,r;
	cin >> t; //1~1000
	string s;
	while (t--) {
		cin >> r >> s;  //r: 1~8, s�� ���̴� 1~19
		string p = ""; char c;
		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < r; j++) {
				c = s.at(i);
				p += c;
			}
		}
		cout << p << "\n";
	}
}