//���� 2438�� 
//�ܰ躰 - for�� 
//�����-1
//corret!

//���� ������ ���ʹ��� (����for��!)
#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int j = 1; j <= n; j++) {
		for (int i = 0; i < j; i++) {
			cout << "*";
		}
		cout << endl;
	}
}