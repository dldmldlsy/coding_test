//���� 2753�� 21/6/22
//�ܰ躰 if��
//����
//correct! 

//���� �� �б�~

#include<iostream>
using namespace std;
int main() {
//�����̸� 1, �ƴϸ� 0
	int y;
	cin >> y;
	if (y % 4 == 0 && y % 100 != 0) {
		cout << "1" << endl;
	}
	else if (y % 400 == 0) {
		cout << "1" << endl;
	}
	else {
		cout << "0" << endl;
	}
}