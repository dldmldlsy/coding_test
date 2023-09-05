#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    vector<long long> cnt(1001, 0);  //몸무게별 인원 수 저장. 
    for(int i=0; i<weights.size(); i++){
        cnt[weights[i]]++; //해당 몸무게가 인덱스인 값 +1 증가  
    }
    //(2:3, 2:4, 3:4) 비율에 해당하는 값찾기 
    for(int i=0; i<weights.size(); i++){
        //2:3
        if(weights[i]%2 ==0){ //정수여야하므로 나누려는 수의 배수인지(?) 확인 
            long long base = (weights[i]/2)*3;
            if(base <=1000) answer+=cnt[base]; 
        }
        //3:4
        if(weights[i]%3==0){
            long long base = (weights[i]/3)*4; 
            if(base <= 1000){
                answer+= cnt[base];
            }
        }
        //2:4 = 1:2
        long long base = (weights[i]/1)*2; 
        if(base<=1000) answer+=cnt[base];
    }
    
    //몸무게 같은 경우
    for(int i=100; i<=1000; i++){ //몸무게 범위
        if(cnt[i]>=2){
            //nC2 조합 경우의 수
            answer += (long long)(cnt[i]*(cnt[i]-1))/2; 
        }
    }
    
    return answer;
}