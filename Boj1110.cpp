//5�� 24�� 
//���� 1110��. while��
#include<iostream>
using namespace std;
int main() {
	int num; 
	cin >> num;
	int x = num; //ó���� ����. 
	int n1, n2, n3;
	int cycle = 0;
	while (1) {
		if (num < 10) { //�� �ڸ� ��
			n1 = 0;
		}
		else { //���ڸ���
			n1 = num / 10; //���� �ڸ� ��
		}	
		n2 = num - n1*10; //���� �ڸ� �� 
		n3 =(n1 + n2)%10;
		num = n2 * 10 + n3;
		cycle++;
		if (num == x) {
			break;
		}
	}
	cout << cycle << endl;

}