import java.util.*;

class Solution {
    public String[] solution(String my_string) {
        String[] answer = {};
        
        int len = my_string.length();
        answer = new String[len];
        for(int i=0; i<len; i++){
            answer[i] = my_string.substring(len-1-i);
        }
        
        Arrays.sort(answer);
        return answer;
    }
}