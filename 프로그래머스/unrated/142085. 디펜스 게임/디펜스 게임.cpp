#include <string>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int> pq; 
int solution(int n, int k, vector<int> enemy) {
    int cnt = enemy.size(); 
    int i=0; 
    for(i=0; i<cnt; i++){
        if(n>= enemy[i]){ //보유 병사 수 >= 공격 수
            n -= enemy[i]; //보유병사수 차감
            pq.push(enemy[i]); 
        }else{
            if(!k){
                break;
            }
            if(!pq.empty() && (pq.top()>enemy[i])){
                n+= pq.top(); 
                pq.pop(); 
                n-=enemy[i];
                pq.push(enemy[i]);
            }
            k--;//무적권 사용
        }
    }
    return i; //라운드 수 반환
}