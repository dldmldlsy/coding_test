//���� 11720�� 21/7/12
//�ܰ躰 ���ڿ�
//������ �� - correct!

//���ڿ����� at�� �̿��Ͽ� �ѹ��ھ� �и��ϰ� '0'�� ���༭ ���ڷ� �ٲٴ� ��!
#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	char c; 
	int d; int sum = 0;
	for (int i = 0; i < n;i++) {
		c=s.at(i);
		d = c - '0';
		sum += d;
	}
	cout << sum;

}