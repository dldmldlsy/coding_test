//백준 15552번 21/6/23
//단계별 - for문

//cin.tie(NULL), ios_base::sysnc_with_stdio(false),\n 을 이용해 출력속도 높이기. 
//t가 최대 백만개이므로 그냥 하던대로 하면 시간초과
#include<iostream>
using namespace std;
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	
	int t, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << a + b << "\n";
	}
}