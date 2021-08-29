//����11286��
//�켱����ť-������
//�ð��ʰ��Ф�... �̰� �ȵǴ� ������ ����?? 
//pair�� �ϸ� �Ǵµ� �̰� �ȵǴ� �������� ã��. 
//#include<iostream>
//#include<deque>
//#include<algorithm>
//using namespace std;
//bool cmp(int a, int b) {
//	if (abs(a) == abs(b)) return a < b;
//	return abs(a) < abs(b);
//}
//int main() {
//	ios_base::sync_with_stdio(0);
//
//	cin.tie(0);
//
//	int n; 
//	cin >> n; 
//	int tmp;
//	deque<int> d;
//	while (n--) {
//		cin >> tmp;
//		if (tmp != 0) { //0�� �ƴϸ� �Է�
//			d.push_back(tmp);
//			sort(d.begin(), d.end(), cmp);
//		}
//		else {
//			if (d.empty()) cout << 0 << "\n";
//			else { cout << d.front() << "\n";  d.pop_front(); }
//		}
//	}
//
//}


#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);

	cin.tie(0);

	int n;
	cin >> n;
	int tmp;
	priority_queue<pair<int,int>> q;
	while (n--) {
		cin >> tmp;
		if (tmp != 0) { //0�� �ƴϸ� �Է�
			q.push(make_pair(-abs(tmp),-tmp));
		}
		else {
			if (q.empty()) cout << 0 << "\n";
			else { cout << -q.top().second << "\n";  q.pop(); }
		}
	}

}