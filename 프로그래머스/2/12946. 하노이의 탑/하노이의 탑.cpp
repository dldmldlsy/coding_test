#include <string>
#include <vector>

using namespace std;

void hanoi(int n, int from, int to, vector<vector<int>>& answer){
    if(n==1){
        answer.push_back({from, to});
        return; //탈출~
    }
    
    hanoi(n-1, from, 6-from-to, answer); //n-1개 원판을 시작점, 도착점 제외한 곳으로 이동 
    hanoi(1, from, to, answer); // n번째 원판을 도착점으로 이동
    hanoi(n-1, 6-from-to, to, answer); //n-1개의 원판을 도착점으로 이동 
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(n, 1, 3, answer);
    return answer;
}