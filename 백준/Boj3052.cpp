//백준 3052번 
//단계별 배열 
//나머지 -correct!

// 좀 헤맸음 더 간단한 방법찾아보기
#include<iostream>
using namespace std;

int main() {

    int a[10], x; int k = 0;
    for (int i = 0; i < 10; i++) {
        a[i] = 0;
    }
    bool Same = false; int count = 0;
    for (int i = 0; i < 10; i++) {

        cin >> x;
        a[i] = x % 42;
        for(int j = 0; j < i; j++) {
            if (a[i] == a[j])
            {
                Same = true; break;
            }
        }
        if (Same == false) count++;
        Same = false;
    }

    cout << count << endl;


 }