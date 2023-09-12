#include <string>
#include <vector>
//#include <algorithm>
#include <stack> 
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0; //최소 이동 거리 
    //cap: 최대 가능 상자 수
    //deliveries: 배달할 택배 수
    //pickups: 수거할 택배 수
    
    int box = 0; 
    stack<int> go, back; 
    //각 집마다 배달상자 수와 수거상자 수 구분하여 스택에 저장. 
    for(int i=0; i<deliveries.size(); i++){
        go.push(deliveries[i]);
        back.push(pickups[i]);
    }

    
    //배달상자나 수거상자가 비어있지 않고 + 가장 먼 집의 택배나 회수상자가 없을 경우 stack에서 제거하여 top을 바꿔줌 
    while(!go.empty() && !go.top()){
        go.pop(); 
    }
    while(!back.empty()&& !back.top()){
        back.pop(); 
    }
    
    while(!(go.empty()&&back.empty())){ //둘다 빌 때까지 
    
        //가장 먼 거리는 꼭 다녀올테니 이동거리에 추가
        answer+=max(go.size()*2, back.size()*2); //왕복 거리 중 가장 큰 값 (가장 먼 거리)
         
        box = 0; //현재 트럭에 실은 상자 수
        while(!go.empty()&&box<=cap){//택배할 게 남아있고, 현재 상자 수가 최대범위안에 속할 때
            if(go.top()+box<=cap){ //현재 상자 수 + 가장 먼거리 배달상자 수 <= 최대 범위 (= 먼거리 집에 배달할 택배상자 다 실을 수 있을 때)
                box+=go.top();  //현재 상자에 추가
            }else{ //택배 다 실을 수 없을 때
                go.top() -= (cap-box); //해당 집의 택배 수 변경: 실을 수 있는 택배 수만 싣고 남기기
                break; //반복문 탈츌 
            }
            //가장 먼집의 배달할 택배상자 담고도 자리가 남으면 그다음 먼 집의 택배상자 담아야 하므로 top바꿔주기 
            go.pop(); //가장 먼집 택배상자 처리 완료.  
        }
        // 가능한만큼 실어서 택배 배달 오나료. -> 현재 트럭 상자수 0개 
        box = 0; 
        //돌아오면서 최대한 회수할 거 
        while(!back.empty() && box<= cap){ //회수할 게 남아있고, 현재 상자 수 <= 최대범위
            if(back.top()+box<=cap){//현재 상자 수 + 가장 먼거리 회수 상자 수 <= 최대 범위 (=먼거리 회수상자 다 싣기)
                box +=back.top(); 
            }else{ // 다 실을 순 없을 때
                back.top() -= (cap-box); //실을 수 있는 만큼만 싣고 남기기
                break;
            }
            back.pop(); //가장 먼 집의 회수 상자 처리 완료
        }
    }
    
    
    return answer;
}