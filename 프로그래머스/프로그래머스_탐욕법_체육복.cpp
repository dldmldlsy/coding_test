#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int studentN = n; 
    vector<int> lost_num = lost;
    vector<int> reserve_num = reserve; 
    int count = studentN - lost_num.size(); //���� ü������ ���� �ִ� �л� �� 
    for (int i = 0; i < lost_num.size(); i++) { //�Ȱ����� �л� ��ȣ�� �迭�� ���鼭 
        for (vector<int> ::iterator iter = reserve_num.begin(); iter < reserve_num.end(); iter++) {
            if (lost_num[i] == *iter - 1 || lost_num[i] == *iter + 1) {
                cout << *iter << endl;
                reserve_num.erase(iter); count++;
            }
        }
    }
    answer = count;
    return answer;
}
int main() {
    cout<<solution(5, { 2,4 }, { 1,3,5 });
}