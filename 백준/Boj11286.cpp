//����11286��
//�켱����ť-������
//�ð��ʰ��Ф�
#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
bool cmp(int a, int b) {
	if (abs(a) == abs(b)) return a < b;
	return abs(a) < abs(b);
}
int main() {
	int n; 
	cin >> n; 
	int tmp;
	deque<int> d;
	while (n--) {
		cin >> tmp;
		if (tmp != 0) {
			d.push_back(tmp);
			sort(d.begin(), d.end(), cmp);
		}
		else {
			if (d.empty()) cout << 0 << endl;
			d.pop_front();
		}
	}

}