//백준 2562번
//단계별 배열 
//최댓값 - correct!

//t를 0으로 초기화 안해줘서 엄청 오래 걸렸음!
#include<iostream>
using namespace std;
int main() {
	int x;
	int a[9];
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
	}
	int m = a[0]; int t = 0;
	for (int i = 1; i < 9; i++) {
		if (m < a[i])
		{
			m = a[i]; t = i;
		}
	}
	cout << m << "\n" << t + 1 << endl;
}

//이거 원인찾기
//#include<iostream>
//using namespace std;
//int main() {
//	int x;
//	int m ;
//	cin >> x; m = x; int t=1;
//	for (int i = 0; i < 8; i++) {
//		cin >> x; 
//		if (x > m) {
//			m = x; t = i + 1;
//		}
//	}
//	cout << m << "\n" << t;
//
//}
