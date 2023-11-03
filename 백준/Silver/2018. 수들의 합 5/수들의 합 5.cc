//백준 10986번 나머지 합
/*
* 투포인터 사용
*/
#include <iostream>
using namespace std; 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int startIdx = 1; 
	int endIdx = 1; 
	int sum = 1; // 두 포인터 모두 1에서 시작 
	int cnt = 1; // n 하나인 경우가 디폴트 
	while (endIdx != n) {
		if (sum == n) {
			cnt++; 
			endIdx++; 
			sum = sum + endIdx;
		}else if (sum < n) {
			endIdx++; 
			sum = sum + endIdx; 
		}
		else { //sum>n
			sum = sum - startIdx; 
			startIdx++;
		}
	}
	cout << cnt << "\n";
}
