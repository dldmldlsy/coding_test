#include <string>
#include <vector>
#include<queue>
#include<functional>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> min_heap;//오름차순
    priority_queue<int, vector<int>, less<int>> max_heap; //내림차순
    int size = 0; //가상 이중우선순위큐의 사이즈
    for (int i = 0; i < operations.size(); i++) {

        if (size == 0) { //큐가 비면 최소힙 최대힙도 비워주는 작업  (!!) 
            while (!min_heap.empty()) min_heap.pop();
            while (!max_heap.empty()) max_heap.pop();
        }
        if (operations[i] == "D 1") {  //최댓값 삭제
            if (size == 0) continue;
            max_heap.pop(); size--;
        }
        else if (operations[i] == "D -1") {// 최솟값 삭제
            if (size == 0) continue;
            min_heap.pop(); size--;
        }
        else { //숫자 삽입
            int new_ = stoi(operations[i].substr(2)); //I 숫자=> index 2부터끝까지의 문자열(숫자부분)을 int형으로 바꿔서 저장
            min_heap.push(new_); max_heap.push(new_); //숫자를 두 큐에 삽입.
            size++; //이중 큐 size++
        }
    }
    if (size == 0) {// 연산 다 했는데 큐가 비었으면 
        answer.push_back(0); answer.push_back(0); 
        return answer; //[0,0]리턴
    }
    //비지않았으면 최댓값 최소값 출력.
    answer.push_back(max_heap.top()); 
    answer.push_back(min_heap.top());
    return answer;
}