#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    int day, plusDay; 
    
    for(int i=0; i<progresses.size(); i++){
        day =  100-progresses[i]; //남은 진도율 
        plusDay = day/speeds[i]; //남은 진도율 / 개발속도 = 추가 작업일
        if(day%speeds[i]>0){ //나머지가 있으면 
            plusDay++; //추가 작업일 +1
        }
        q.push(plusDay); //큐에 저장
    }

    int cnt =0; 
    int now, next;
    while(!q.empty()){
        now = q.front(); //가장 앞에 있는 작업의 추가 작업일 
        cnt = 1; //배포 기능수 +1
        q.pop(); //큐에서 꺼내기
        if(q.empty()) { answer.push_back(cnt); break;}
        next = q.front(); //다음 작업의 추가 작업일
        //다음 작업의 추가 작업일 < 현재 추가작업일 -> 더 긴 추가작업일이 나올 때까지 반복
        while(now>=next){ 
        //현재 추가작업일 >= 다음 추가 작업일 = -> 앞 기능과 함께 배포
            cnt++; // 배포 기능 수 +1
            q.pop(); //큐에서 꺼내기
            if(q.empty()) break;
            next = q.front(); 
        }
        answer.push_back(cnt);
    }        
    
    return answer;
}