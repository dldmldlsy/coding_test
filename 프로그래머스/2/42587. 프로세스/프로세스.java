/*
    큐: 대기중인 프로세스들이 있음.
    1. 큐에서 하나를 꺼냄. 
    2. 큐에 더 높은 우선순위의 프로세스가 있으면 방금 꺼낸 거 다시 넣음
    3. // 없다면 방금 꺼낸 프로세스 실행 -> 실행한 프로세스는 그대로 종료 
        - 프로세스는 1~100개, 우선순위는 숫자 클수록 높음 
    특정 프로레스가 몇번째로 실행되는지? 
    입력: 대기중인 프로세스들의 우선순위 배열(배열값이 해당인덱스의 프로세스의 우선순위), 실행순서 알고싶은 프로세스의 큐에서의 위치 index 
    출력: 궁금한 프로세스의 실행 순서! 
*/

import java.util.*;

class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 0;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder()); 
        for(int num : priorities){
            pq.offer(num);
        }
        
        while(!pq.isEmpty()){
            for(int i=0;i<priorities.length; i++){
                if(pq.peek()==priorities[i]){ 
                    pq.poll(); 
                    answer++; 
                    if(i==location){
                        return answer;
                    }
                }
            }
        }
        return answer;
    }
}