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
		cout.setf(ios::showpoint);
		cout.precision(5);
		cout << floor(c/ (double)n * 1000000+0.5)/1000<< "%" << endl;
	}
}