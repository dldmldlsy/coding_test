#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int studentN = n; 
    vector<int> lost_num;
    vector<int> reserve_num = reserve; 
    int count = studentN - lost.size(); //���� ü������ ���� �ִ� �л� �� 
    cout << count << endl;
    for (vector<int> ::iterator i = lost.begin(); i < lost.end(); i++) { //�Ȱ����� �л� ��ȣ�� �迭�� ���鼭 
       // cout << "�׳�" << *i << endl;
        bool self = false;

        for (vector<int> ::iterator iter = reserve_num.begin(); iter < reserve_num.end(); iter++) {
            if (*i == *iter ) {
               // cout << *iter << endl;
                reserve_num.erase(iter); 
                count++; self = true;
                break; 
            }
        }
        if (!self) lost_num.push_back(*i);
       // cout << "!" << endl;
    }
   // cout << ": " << lost_num.size() << endl;
    for (int i = 0; i < lost_num.size(); i++) { //�Ȱ����� �л� ��ȣ�� �迭�� ���鼭 
        for (vector<int> ::iterator iter = reserve_num.begin(); iter < reserve_num.end(); iter++) {
            if (lost_num[i] == *iter - 1 || lost_num[i] == *iter + 1) {
              // cout << *iter << endl;
                reserve_num.erase(iter); count++;
                break;
            }
        }
    }
    answer = count;
    return answer;
}
int main() {
    cout<<"��"<<solution(5, {2,4}, {1,3,5});
}