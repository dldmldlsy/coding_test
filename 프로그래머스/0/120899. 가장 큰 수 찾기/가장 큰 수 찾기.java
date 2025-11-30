import java.util.*;

class Solution {
    public int[] solution(int[] array) {
        int[] answer = {};
        int max = 0, idx = -1;
        for(int i = 0; i<array.length; i++){
            if(max<array[i]){
                max = array[i];
                idx = i;
            }
        }
                
        answer = new int[2];
        answer[0] = max;
        answer[1] = idx;
        return answer;
    }
}