//백준 2439번 21/6/25
//단계별 -for문
//별찍기-2

//오른쪽정렬!
#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j =0; j<n-i; j++) 
			cout << " ";
		for (int j = 0; j < i; j++) 
			cout << "*";
		cout << endl;
	}
}