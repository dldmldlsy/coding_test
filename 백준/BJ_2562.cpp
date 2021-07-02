//백준_단계별_배열_2번
//"최댓값"
//실패 ㅠ 틀렸습니다!
/*
문제)
9개의 서로 다른 자연수가 주어질 때, 
이들 중 최댓값을 찾고 그 최댓값이 몇 번째 수인지를 구하는 프로그램을 작성하시오.
예를 들어, 서로 다른 9개의 자연수 3, 29, 38, 12, 57, 74, 40, 85, 61이 주어지면, 
이들 중 최댓값은 85이고, 이 값은 8번째 수이다.
*/
#include <iostream>
using namespace std;
int main() {
    int* arr = new int[9];
    for (int i = 0; i < 9; i++)
    {
        cin >> arr[i];
        cout << endl;
    }
    int max = arr[0];
    int k = 1;
    for (int i = 1; i < 9; i++) {
        if (max < arr[i]) {
            max = arr[i];
            k = i;
        }
        else
            max = max;
    }
    cout << max << endl;
    cout << k << endl;
    return 0;
}