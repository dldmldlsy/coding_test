#include <string>
#include <vector>
#include<queue>
#include<algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> q; //순서대로 넣을 실행대기 큐
    
    for(int i=0; i<priorities.size(); i++){
        q.push(priorities[i]);
    }
    
    //우선순위 내림차순 정렬
    sort(priorities.begin(), priorities.end(), greater<int>()); 
    
    //큐가 빌때까지 프로세스 실행 
    int now;
    
    while(1){
        now = q.front(); //가장 앞에 있는 프로세스의 우선순위;
        if(now == priorities[0]){ 
            answer++; 
            q.pop(); 
            priorities.erase(priorities.begin());
            if(location==0) return answer;
            else location--;
        }
        else{
            q.push(now);
            q.pop();
            location--; 
            if(location<0) location=q.size()-1;
        }
    }
    return answer;
}