#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int studentN = n;  //�л���
    // lost: �������� �л� ��ȣ �迭
    vector<int> lost_num; // �������� ���µ� �������� �л� ��ȣ �迭 
    vector<int> reserve_num = reserve; // �������� ������ �л� ��ȣ �迭 
    int count = studentN - lost.size(); //������ ���� �� �ִ� �л� �� = ���� ü������ ���� �ִ� �л� �� (�л���-�Ҿ���� �л���)  
    for (vector<int> ::iterator i = lost.begin(); i < lost.end(); i++) {  //�������� �л� ��ȣ�� �迭�� ���鼭 
        bool self = false; // �ڱ⿩���� �ڱⰡ ��������. 

        for (vector<int> ::iterator iter = reserve_num.begin(); iter < reserve_num.end(); iter++) {   //�������� ���� �л� ��ȣ�� ��
            if (*i == *iter ) { // ���� ��ȣ�� ������ -> �ڱ� �������� �ڱⰡ ���� 
               // cout << *iter << endl;
                reserve_num.erase(iter);  // �������� ���� �л� ��ȣ �迭���� �ش� ��ȣ�� ����. 
                count++; self = true; // ���� ���� �� �ִ� �л� �� +1, �ڱ� ������ �ڱⰡ �������� true�� �ٲ�.  
                break; //�ݺ��� Ż��
            }
        }
        if (!self) lost_num.push_back(*i); // false=>  �������ߴµ������� ������ �������� �л��̹Ƿ� lost_num�� �߰�. 
    }
    for (int i = 0; i < lost_num.size(); i++) {
        cout << lost_num[i] << " ";
    }
    cout << endl;
    sort(lost_num.begin(), lost_num.end());
    for (int i = 0; i < lost_num.size(); i++) {
        cout << lost_num[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < lost_num.size(); i++) { //�������� �л� ��ȣ�� �迭�� ���鼭 
        for (vector<int> ::iterator iter = reserve_num.begin(); iter < reserve_num.end(); iter++) { //�����ʰ����� �л���ȣ�迭�� ��. 
            if (lost_num[i] == *iter - 1 || lost_num[i] == *iter + 1) { //�������� �л���ȣ�� �����ʰ����� �л���ȣ-1 or +1���϶�
                reserve_num.erase(iter); count++; //�������� �ش��л����� �ֹǷ� �����л���ȣ���� �����, count����. 
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