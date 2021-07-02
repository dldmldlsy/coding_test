//백준 2577번
//단계별 배열- 숫자의 개수
//correct! 

//배열미사용
#include<iostream>

using namespace std;

int main() {

    int a, b, c;

    cin >> a >> b >> c;

    int mul = a * b * c;

    //int a[10]; //0~9

    int count, k, mul2;

    for (int i = 0; i < 10; i++) {

        mul2 = mul;

        count = 0;

        k = 0;

        while (mul2 != 0) {

            k = mul2 % 10;

            if (k == i) count++;

            mul2 = mul2 / 10;

        }

        cout << count << endl;



    }

}