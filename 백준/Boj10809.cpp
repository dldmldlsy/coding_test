//���� 10809��
//�ܰ躰 - ���ڿ�

//���ĺ� ã�� - correct! 
#include<iostream>
using namespace std;
int main() {
	string alp;
	cin >> alp;
	int n = alp.length();
	int a = 'a'; //a�� �ƽ�Ű�ڵ尪
	int z = 'z'; int alp_asc; 
	for (int i = a; i <= z; i++) {
		bool isChar = false;
		for (int j = 0; j < n;j++) {
			alp_asc = alp.at(j);
			if (alp_asc == i) {
				isChar = true; //���ĺ�����. 
				cout << j << " ";
				break;
			}
		}
		if (!isChar) cout << -1 << " ";
	}
	
	
}