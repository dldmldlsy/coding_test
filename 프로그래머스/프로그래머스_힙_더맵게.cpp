#include <string>
#include <vector>
#include<queue>
#include<functional>

using namespace std;

int solution(vector<int> scoville, int k) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;  //min heap
    int n = scoville.size(); //�� ���İ���
  
    int mix; //���� ������ ���ں�����
    for (int i = 0; i < n; i++) {
        pq.push(scoville[i]); //ť�� ���ں����� �� ����. (���� �ź��� ��)
    }
    bool k_up = true;  //��� ������ k�̻������ƴ��� 
    int min =pq.top();    //���� �������� ���� 
    int a, b;  //���� ��������, �״������� �������� ����
    int count = 0; //Ƚ��
    while (min < k) { //����������� ������ K���� ���� ��� �ݺ� (���� �������� ������ K�̻��� �ɶ����� �ݺ�) 
        if (pq.size() == 1) { k_up = false; break; } //1��
        //���� ���� �ΰ� a,b ť���� ����.
        a = min; pq.pop();  
        b = pq.top(); pq.pop();
       pq.push(a + b*2); // ��� �� ���ں� ������ push.
        count++;//Ƚ������.
        min = pq.top();  //����տ� �ִ� �� ���� �ȸſ� ����
    }
    if (!k_up) return-1;
    answer = count;
    return answer;
}