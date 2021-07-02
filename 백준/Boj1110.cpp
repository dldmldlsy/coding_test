//5월 24일 
//백준 1110번. while문
#include<iostream>
using namespace std;
int main() {
	int num; 
	cin >> num;
	int x = num; //처음수 저장. 
	int n1, n2, n3;
	int cycle = 0;
	while (1) {
		if (num < 10) { //한 자리 수
			n1 = 0;
		}
		else { //두자리수
			n1 = num / 10; //십의 자리 수
		}	
		n2 = num - n1*10; //일의 자리 수 
		n3 =(n1 + n2)%10;
		num = n2 * 10 + n3;
		cycle++;
		if (num == x) {
			break;
		}
	}
	cout << cycle << endl;

}