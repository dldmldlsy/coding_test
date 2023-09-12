#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    vector<long long> cnt(1001, 0);  //몸무게별 인원 수 저장할 벡터 생성 (몸무게 최대 수만큼 0으로 초기화)
    //몸무게별 인원 수 저장
    for(int i=0; i<weights.size(); i++){
        cnt[weights[i]]++; //해당 몸무게가 인덱스인 값 +1 증가  
    }
    
    //x:y=a:b => x*b= y*a -> x 몸무게만 알고, a,b는 2,3,4중 하나 -> 평형을 이루는 몸무게 y = x*b/a -> y는 정수여야하므로 a의 배수여야함! 
    //(2:3, 2:4, 3:4) 비율에 해당하는 값찾기 
    for(int i=0; i<weights.size(); i++){
        //2:3 -> y = x*3/2
        if(weights[i]%2 ==0){ //정수여야하므로 나누려는 수의 배수인지(?) 확인 
            long long base = (weights[i]*3)/2;
            if(base <=1000) answer+=cnt[base]; 
        }
        //3:4 -> y = x*4/3
        if(weights[i]%3==0){
            long long base = (weights[i]*4)/3; 
            if(base <= 1000){
                answer+= cnt[base];
            }
        }
        //2:4 = 1:2 -> y = x*2/1
        long long base = (weights[i]*2)/1; 
        if(base<=1000) answer+=cnt[base];
    }
    
    //몸무게 같은 사람이 2명 이상인 경우
    for(int i=100; i<=1000; i++){ //몸무게 범위
        if(cnt[i]>=2){
            //nC2 조합 경우의 수
            answer += (long long)(cnt[i]*(cnt[i]-1))/2; 
        }
    }
    
    return answer;
}