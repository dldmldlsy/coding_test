//���� 2588�� 21/6/22
//�˰��� �ܰ躰-����°���Ģ����
//����

#include<iostream>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	int b1, b2, b3;
	b1 = b / 100;
	b2 = (b - b1 * 100) / 10;
	b3 = (b - b1 * 100 - b2 * 10) ;
	cout << a * b3 << endl;
	cout << a * b2 << endl;
	cout << a * b1 << endl;
	cout << a * b << endl;
}