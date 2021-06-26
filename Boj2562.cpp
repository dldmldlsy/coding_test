//#include<iostream>
//using namespace std;
//int main() {
//	int x;
//	int m ;
//	cin >> x; m = x; int t;
//	for (int i = 0; i < 8; i++) {
//		cin >> x; 
//		if (x > m) {
//			m = x; t = i + 2;
//		}
//	}
//	cout << m << "\n" << t;
//
//}
#include<iostream>
using namespace std;
int main() {
	int x;
	int a[9];
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
	}
	int m = a[0]; int t;
	for (int i = 1; i < 9; i++) {
		if (m < a[i])
		{
			m = a[i]; t = i;
		}
	}
	cout << m << "\n" << t+1<< endl;
}