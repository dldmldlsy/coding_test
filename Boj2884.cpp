//���� 2884��
//�ܰ躰 if��
//�˶��ð�
//correct! 

//����� �������� ��� ����
#include<iostream>
using namespace std;
int main() {
	//45�� ���� �˶� �����ϱ� 0:0~23:59
	int h, m, hh, mm; //�ʱ� h, m ��� hh, mm
	cin >> h >> m; 
	int totalM = h * 60 + m;
	int reTotal = totalM - 45;
		hh = reTotal / 60;
		mm = reTotal - hh * 60; 
		if (mm < 0) {
			hh += 23; mm += 60;
		}
	cout << hh << " " << mm << endl;
}