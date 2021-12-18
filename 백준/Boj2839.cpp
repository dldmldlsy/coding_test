//백준 2839번: 설탕배달 
//기본수학1
//correct!


#include<iostream>
using namespace std;
int main() {
	int N; //N킬로그램
	cin >> N; //입력받음
	int a5 = N / 5;  //5로 나눴을때의 몫. 
	int r = 0; //봉지개수
	bool make = false; //N킬로그램을 만들 수 있는지 가능여부

	for (int i = a5; i>=0; i--) { //a5부터 내려가면서 반복
		int tmp = N - 5 * i; //N을 5로 나눈 나머지 
		if (tmp == 0) { //바로 나누어떨어지면 
			r = i; make = true; 
			break; //그대로 반복문 탈출
		}
		else if(tmp%3==0){ //남은 수가 3으로 나누어떨어지면 
			r = i + tmp / 3; //5로 나눴을때의 몫과 3으로 나눴을때의 몫을 더한 게 봉지개수. 
			make = true;
			break;//반복문탈출
		}
	}
	if (!make) { //만들 수 없다면 
		cout << -1;//-1출력
	}
	else { cout << r; }//만들 수 있다면 봉지개수 r출력.  
	

}