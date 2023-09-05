#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while(storey!=0){
        
        int n = storey % 10; // 가장 끝의 수 = 일의 자리 수
        
        if(n==5){ 
            
            //가장 끝 수가 5-> 그 앞자리 수보고 올림할지 내림할지 결정
            int tmp = (storey/10)%10; //임시변수: 십의자리수 = 끝에서 2번째    
            if(tmp>=5){ // 5이상인 경우-> 위로 이동(5층 올라감)
                storey /= 10;  // 일의자리 없애고 
                storey += 1;  //+1
            }else{//5미만인 경우-> 아래로 이동(5층 내려감)
                storey /= 10;
            }
            answer += 5; //어차피 이동 수는 5
            
        }else if(n>5){ //5보다 큰 경우 
            answer += 10-n; //10-n만큼 위로 이동
            storey /= 10; 
            storey += 1; 
        }else { //5보다 작은 경우 
            answer += n; //n만큼 아래로 이동
            storey /= 10; 
        }
    }
    return answer;
}