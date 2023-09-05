#include <string>
#include <vector>
//#include <algorithm>
#include <stack> 
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    //cap: 최대 가능 상자 수
    //deliveries: 배달할 택배 수
    //pickups: 수거할 택배 수
    
    int box = 0; 
    stack<int> go, back; 
    
    for(int i=0; i<deliveries.size(); i++){
        go.push(deliveries[i]);
        back.push(pickups[i]);
    }

    
    //택배나 회수 배열이 비어있지 않고, 가장 먼 집의 택배나 회수상자가 없을 경우 stack에서 제거하여 top을 바꿔줌 
    while(!go.empty() && !go.top()){
        go.pop(); 
    }
    while(!back.empty()&& !back.top()){
        back.pop(); 
    }
    
    while(!(go.empty()&&back.empty())){ //둘다 빌 때까지 
        answer+=max(go.size()*2, back.size()*2); //왕복 거리 중 큰 값 (가장 먼 거리)
         
        box = 0; //현재 트럭에 실은 상자 수
        while(!go.empty()&&box<=cap){//택배할 게 있고, box 수가 최대범위안에 속할 때
            if(go.top()+box<=cap){ //택배 실을 수 있을 때
                box+=go.top(); 
            }else{ //택배 다 실을 수 없을 때
                go.top() -= (cap-box); //해당 집의 택배 수 변경: 실을 수 있는 택배수만 싣고 남기기
                break; 
            }
            go.pop(); //가장 먼집 택배상자 처리 완료. 
        }

        box = 0; 
        while(!back.empty() && box<= cap){
            if(back.top()+box<=cap){
                box +=back.top(); 
            }else{
                back.top() -= (cap-box);
                break;
            }
            back.pop();
        }
    }
    
    
    return answer;
}