import java.util.*;

class Solution {
    public String solution(String my_string) {
        String answer = "";
        answer = my_string.toLowerCase();
        ArrayList<Character> list = new ArrayList<>();
        for(char c : answer.toCharArray()){
            list.add(c);
        }
        
        Collections.sort(list);
        
        answer = "";
        
        for(char c : list){
            answer += c;
        }
        return answer;
    }
}