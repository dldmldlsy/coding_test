//���� 2941��
//�ܰ躰 - ���ڿ�
//ũ�ξ�Ƽ�� ���ĺ�

//for���ȿ��� �߰��� ����� ��������i�� �ٲٸ� ������ ������Ű���� ���� üũ�������. 
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