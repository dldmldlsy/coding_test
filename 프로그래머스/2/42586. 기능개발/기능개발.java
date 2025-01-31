import java.util.Queue; 
import java.util.LinkedList; 

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int[] answer = {};
        
        int[] ans = new int[100];
        
        Queue<Integer> queue = new LinkedList<>();
        int day = 0; 
        for(int i=0; i<progresses.length; i++){
            day = (int) Math.ceil((100-progresses[i])/(double)speeds[i]); 
            queue.offer(day);
        }
        int front;
        int tmp; 
        int cnt = 0; 
        int idx = 0; 
        while(!queue.isEmpty()){
            cnt = 0; 
            front = queue.peek();
            queue.poll(); 
            cnt++; 
            while(!queue.isEmpty()&&front>=queue.peek()){
                cnt++;
                queue.poll();
            }
            ans[idx] = cnt; 
            idx++; //총 배포 일수보다 하나 증가한 값으로 반복문 탈출
        }
        
        answer = new int[idx]; 
        for(int i=0; i<idx; i++){
            answer[i] = ans[i];
        }
        
        return answer;
    }
}