import java.util.*;

class Solution {
    public int[] solution(int[] numbers) {
        int[] answer = {};
        
        Set<Integer> set = new HashSet<Integer>();
        for(int i=0; i<numbers.length-1; i++){
            for(int j=i+1; j<numbers.length; j++){
                set.add(numbers[i]+numbers[j]);
            }
        }
        
        answer = new int[set.size()];
        int i=0;
        for(Integer s : set){
            answer[i++] = s;
        }
        
        Arrays.sort(answer);
    
        return answer;
    }
}