import java.util.*;

class Solution {
    public int[] solution(int[] num_list) {
        int[] answer = {};
        Arrays.sort(num_list);
        answer = new int[5];
        
        for(int i=0; i<5; i++){
            answer[i] = num_list[i];
        }
        return answer;
    }
}