#include <string>
#include <vector>
#include<queue>
#include<functional>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> min_heap;//��������
    priority_queue<int, vector<int>, less<int>> max_heap; //��������
    int size = 0; //���� ���߿켱����ť�� ������
    for (int i = 0; i < operations.size(); i++) {

        if (size == 0) { //ť�� ��� �ּ��� �ִ����� ����ִ� �۾�  (!!) 
            while (!min_heap.empty()) min_heap.pop();
            while (!max_heap.empty()) max_heap.pop();
        }
        if (operations[i] == "D 1") {  //�ִ� ����
            if (size == 0) continue;
            max_heap.pop(); size--;
        }
        else if (operations[i] == "D -1") {// �ּڰ� ����
            if (size == 0) continue;
            min_heap.pop(); size--;
        }
        else { //���� ����
            int new_ = stoi(operations[i].substr(2)); //I ����=> index 2���ͳ������� ���ڿ�(���ںκ�)�� int������ �ٲ㼭 ����
            min_heap.push(new_); max_heap.push(new_); //���ڸ� �� ť�� ����.
            size++; //���� ť size++
        }
    }
    if (size == 0) {// ���� �� �ߴµ� ť�� ������� 
        answer.push_back(0); answer.push_back(0); 
        return answer; //[0,0]����
    }
    //�����ʾ����� �ִ� �ּҰ� ���.
    answer.push_back(max_heap.top()); 
    answer.push_back(min_heap.top());
    return answer;
}