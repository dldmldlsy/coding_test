//���� 1427
//�ܰ躰 - ����
//��Ʈ�λ��̵� (�迭����)

// �ΰ��� ������� ǯ. 1) ���ڷ� �ٲ㼭 �����ѵڿ� �Ųٷ� ���, 2) ���ڸ� �����ؼ� �Ųٷ� ���.
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	string s;
	cin >> s;
	//vector<int>v;
	//int num = 0;
	//for (int i = 0; i < s.size(); i++) {
	//	num = s.at(i) - '0';
	//	v.push_back(num);
	//}
	//sort(v.begin(), v.end());
	sort(s.begin(), s.end());
	for (int i = s.size() - 1; i >= 0; i--) {
		cout << s.at(i);
	}
}