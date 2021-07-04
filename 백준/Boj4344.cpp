//백준 4344번
//단계별 - 배열 
// 평균은 넘겠지

//소수점자리제한하는 법!!
#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n; 
		int* a = new int[n];
		int sum = 0;
		for(int i=0;i<n;i++){
			cin >> a[i];
			sum += a[i];
		}
		double aver = sum / (double)n;
		int c =0;
		for (int i = 0; i < n; i++) {
			if (a[i] > aver)
				c++;
		}

		cout << fixed;
		cout.precision(3);
		cout << (c/(double)n)*100<< "%" << endl;
	}
}