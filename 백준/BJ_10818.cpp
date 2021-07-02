//백준 단계별_배열_1번 
//"최소, 최대"
//문제) N개의 정수가 주어진다. 이때, 최솟값과 최댓값을 구하는 프로그램을 작성하시오.
// 성공

#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (min > arr[i])
            min = arr[i];
        else
            min = min;
    }
    for (int i = 1; i < n; i++) {
        if (max < arr[i])
            max = arr[i];
        else
            max = max;
    }
    cout << min << " " << max;
    return 0;
}