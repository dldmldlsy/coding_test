#include <string>
#include <vector>
#include<queue>
#include<functional>

using namespace std;

int solution(vector<int> scoville, int k) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;  //min heap
    int n = scoville.size(); //총 음식개수
  
    int mix; //섞은 음식의 스코빌지수
    for (int i = 0; i < n; i++) {
        pq.push(scoville[i]); //큐에 스코빌지수 다 넣음. (작은 거부터 들어감)
    }
    bool k_up = true;  //모든 음식이 k이상인지아닌지 
    int min =pq.top();    //가장 맵지않은 지수 
    int a, b;  //가장 맵지않은, 그다음으로 맵지않은 지수
    int count = 0; //횟수
    while (min < k) { //가장맵지않은 지수가 K보다 작을 경우 반복 (가장 맵지않은 지수가 K이상이 될때까지 반복) 
        if (pq.size() == 1) { k_up = false; break; } //1개
        //가장 낮은 두개 a,b 큐에서 꺼냄.
        a = min; pq.pop();  
        b = pq.top(); pq.pop();
       pq.push(a + b*2); // 섞어서 새 스코빌 지수를 push.
        count++;//횟수증가.
        min = pq.top();  //가장앞에 있는 게 가장 안매운 지수
    }
    if (!k_up) return-1;
    answer = count;
    return answer;
}