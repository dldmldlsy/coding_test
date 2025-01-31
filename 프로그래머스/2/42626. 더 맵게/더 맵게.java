import java.util.PriorityQueue;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for(int scv : scoville) {
            pq.offer(scv); 
        }
        
        int min, min2, mix; 
        int cnt = 0;
        
        while(pq.size()>1 && pq.peek() < K){
            
            min = pq.peek(); 
            pq.poll(); 
            min2 = pq.peek(); 
            pq.poll(); 
            
            mix = min + min2*2; 
            pq.offer(mix);
            
            cnt++; 
        }
        
        if(pq.peek()<K){
            answer = -1; 
        }else {
            answer = cnt;
        }
        return answer;
    }
}