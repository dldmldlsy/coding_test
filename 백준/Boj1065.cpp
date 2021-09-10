//백준 1065번
//함수 - 한수
// 등차수열을 이루는 수의 개수 구하기
//correct!

#include<iostream>
using namespace std;
int main() {
	int N;//N은 1000이하 자연수.
	cin >> N;
	int count = 0; 
	int a, b, c;
	if (N < 100)//두자리 수, 한자리 수면
		cout << N;
	else { //세자리수면
		for (int i = 100; i <= N; i++) {
			a = i / 100; //백의 자리 수 
			b = (i % 100) / 10;//십의 자리 수 
			c = (i % 100) % 10; //일의 자리 수

			if ((a - b) == (b - c)) //등차인지 확인
				count++; //개수+1
		}
		cout <<(99 + count);
	}

}