#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0; 
    
    vector<int>::iterator iter1, iter2; //큐 포인터 2개
    long long total, sum1, sum2; // 큐1+큐2, 큐1합, 큐2합
    
    iter1 = queue1.begin(), iter2 = queue2.begin(); 
    total =0, sum1=0, sum2=0; 
    
    // 각 큐 합 계산
    for(int i=0; i<queue1.size(); i++){
        sum1+=queue1[i]; 
        sum2+=queue2[i];
    }
    total = sum1+sum2; 
    
    
    //총합이 홀수 -> 애초에 불가능
    if(total%2 != 0 ){
        answer =-1; 
    }
    else{
        while(1){
            if(sum1==sum2){
                break; //두 큐 합 같으면 탈출
            }
            //상대 큐의 끝까지 갔을 경우: 더이상 탐색 x -> 탈출
            if(iter1==queue2.end() || iter2==queue1.end()){
                answer = -1; 
                break;
            }
            
            //원소 이동 
            if(sum1>sum2){//큐1이 더 큼 -> 1->2로 이동
                sum1-= *iter1; 
                sum2+= *iter1; 
                
                iter1++;
                if(iter1==queue1.end()){
                    iter1=queue2.begin(); 
                }
            }else{
                sum2 -= *iter2; 
                sum1 += *iter2; 
                
                iter2++; 
                if(iter2==queue2.end()){
                    iter2=queue1.begin();
                }
            }
            answer++; //이동 횟수 ++
        }
    }
    return answer;
}