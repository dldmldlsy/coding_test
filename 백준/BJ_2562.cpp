//����_�ܰ躰_�迭_2��
//"�ִ�"
//���� �� Ʋ�Ƚ��ϴ�!
/*
����)
9���� ���� �ٸ� �ڿ����� �־��� ��, 
�̵� �� �ִ��� ã�� �� �ִ��� �� ��° �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
���� ���, ���� �ٸ� 9���� �ڿ��� 3, 29, 38, 12, 57, 74, 40, 85, 61�� �־�����, 
�̵� �� �ִ��� 85�̰�, �� ���� 8��° ���̴�.
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