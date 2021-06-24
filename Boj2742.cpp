//백준 2742번 
//단계별 for문

//기찍N

//endl쓰면 시간초과남.
#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int i = n; i > 0; i--) {
		cout << i <<"\n";
	}
}