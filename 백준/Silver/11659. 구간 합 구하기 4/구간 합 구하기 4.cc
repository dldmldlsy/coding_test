//백준 11659번 구간 합 구하기 4 
/*
* n개의 숫자를 입력받아 m번동안 구간합 구하기
* n 최대 100, 000 
*/
#include <iostream>
#include <vector>
using namespace std; 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); 

	int n, m; 
	cin >> n >> m; 
	int* arr = new int[n]; 
	int* sum = new int[n];
	sum[n] = {0};
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i != 0) {
			sum[i] = sum[i - 1] + arr[i];
		}
		else {
			sum[i] = arr[i];
		}
	}
	int i, j; 
	while(m--) {
		cin >> i >> j; 
		if (i == 1) {
			cout << sum[j - 1] << "\n";
		}
		else {
			cout << sum[j-1] - sum[i - 2] << "\n";
		}
	}

}