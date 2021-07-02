//백준 2884번
//단계별 if문
//알람시계
//correct! 

//결과가 음수나올 경우 주의
#include<iostream>
using namespace std;
int main() {
	//45분 일찍 알람 설정하기 0:0~23:59
	int h, m, hh, mm; //초기 h, m 결과 hh, mm
	cin >> h >> m; 
	int totalM = h * 60 + m;
	int reTotal = totalM - 45;
		hh = reTotal / 60;
		mm = reTotal - hh * 60; 
		if (mm < 0) {
			hh += 23; mm += 60;
		}
	cout << hh << " " << mm << endl;
}