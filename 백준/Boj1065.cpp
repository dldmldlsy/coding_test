//���� 1065��
//�Լ� - �Ѽ�
// ���������� �̷�� ���� ���� ���ϱ�
//correct!

#include<iostream>
using namespace std;
int main() {
	int N;//N�� 1000���� �ڿ���.
	cin >> N;
	int count = 0; 
	int a, b, c;
	if (N < 100)//���ڸ� ��, ���ڸ� ����
		cout << N;
	else { //���ڸ�����
		for (int i = 100; i <= N; i++) {
			a = i / 100; //���� �ڸ� �� 
			b = (i % 100) / 10;//���� �ڸ� �� 
			c = (i % 100) % 10; //���� �ڸ� ��

			if ((a - b) == (b - c)) //�������� Ȯ��
				count++; //����+1
		}
		cout <<(99 + count);
	}

}