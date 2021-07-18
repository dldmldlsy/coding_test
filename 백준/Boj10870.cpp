//백준 10870번
//단계별 - 재귀
//피보나치 수 5
#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n; 
	vector<int> v(n+1, 0);
	v[0] = 0; v[1] = 1;
	for(int i = 2; i <=n; i++) {
		v[i]=v[i - 1] + v[i - 2];
	}
	cout << v[n];
}