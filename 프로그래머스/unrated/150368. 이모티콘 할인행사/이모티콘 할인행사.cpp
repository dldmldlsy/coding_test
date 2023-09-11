#include <string>
#include <vector>

using namespace std;
int discount[4]={10, 20, 30, 40};
vector<int> answer(2, 0); //사이즈:2 값:0 으로 초기화 

void dfs(vector<int>, vector<vector<int>>, vector<int>); 
void calculate(vector<int>, vector<vector<int>>, vector<int>);

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> sale; //이모티콘별 할인율 조합을 담은 배열
    dfs(sale, users, emoticons); 
    return answer;
}

void dfs(vector<int> sale, vector<vector<int>> users, vector<int> emoticons){
    if(sale.size() == emoticons.size()){ //할인율 수 = 이모티콘 수
        calculate(sale, users, emoticons); //해당 조건으로 최선의 가입자 수와 매출액 계산
        return;
    }
    //이모티콘 수만큼 할인율 조합 생성
    for(int i=0; i<4; i++){
        sale.push_back(discount[i]); //할인율 설정 
        dfs(sale, users, emoticons); //해당 할인율이용해서 최선의 조건 탐색
        sale.pop_back();  //가장 최근 값 빼기
    }
}

void calculate(vector<int> sale, vector<vector<int>> users, vector<int> emoticons){
    
    int plusNum = 0; int totalRevenue = 0; //플러스 서비스 가입자 수, 총 매출액 
    vector<int> priceByUser(users.size(), 0); //사용자별 누적 구매 가격: 사용자 수만큼 0으로 초기화
    vector<bool> plusCheck(users.size(), false); //플러스 서비스 가입자여부: 사용자 수만큼 false로 초기화
    
    //각 이모티콘마다 할인가격 계산 후 사용자별 해당 이모티콘 구매여부 결정 (혹은 가입여부)
    for(int i=0; i<emoticons.size(); i++){
        int salePrice = (emoticons[i]*(100-sale[i]))/100; //이모티콘 할인가 계산
        //각 사용자마다 
        for(int j=0; j<users.size(); j++){
            if(plusCheck[j]) continue; //이미 플러스 서비스 가입자면 패스
            //사용자의 구매 기준에 따라 구매여부 결정
            if(sale[i]>=users[j][0]){  //해당 이모티콘 할인율 > 사용자 구매 기준 할인율-> 구매
                priceByUser[j]+= salePrice; // 사용자 기존 구매가격 + 현재 이모티콘 할인가격 
                if(priceByUser[j]>=users[j][1]){ // 사용자 구매 가격 >= 사용자 가입 기준 금액 -> 가입
                    plusNum ++; //플러스 서비스 가입자 수 +1 증가
                    priceByUser[j]=0; //사용자 현재 구매가격 0원으로 초기화 (구매 취소)
                    plusCheck[j]=true; //플러스 서비스 가입자 체크 true 
                }
            }
        }
    }
    //총 매출액 계산
    for (int i = 0; i<priceByUser.size(); i++){
        totalRevenue += priceByUser[i]; // 사용자별 구매가격 합산
    }
    //가입자수>기존 기록된 가입자수 or 가입자 수 동일 + 매출액 > 기존 기록된 매출액  -> 갱신 
    if(plusNum > answer[0] || (plusNum ==answer[0] && totalRevenue>answer[1])){
        answer[0]=plusNum ; //가입자 수
        answer[1]=totalRevenue; //매출액
    }
}