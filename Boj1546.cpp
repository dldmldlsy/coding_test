//백준 1546번 
//단계별 배열 - 평균 correct! 

//나눌때 int형 주의
#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	double* a = new double [n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	double m = a[0];
	for (int i = 1; i < n; i++) {
		if (m < a[i]) {
			m = a[i];
		}
	}
	double sum = 0;
	for (int i = 0; i < n; i++) {
		a[i] = a[i]/m *100;
		sum += a[i];
	}
	cout<< sum / n << endl;
}