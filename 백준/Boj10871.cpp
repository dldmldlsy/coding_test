//���� 10871�� 21/6/25
//�ܰ躰 -for��
//x���� ���� ��
//correct!
#include<iostream>
using namespace std;
int main() {
	int n, x,a;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a < x) cout << a << " ";
	}
}