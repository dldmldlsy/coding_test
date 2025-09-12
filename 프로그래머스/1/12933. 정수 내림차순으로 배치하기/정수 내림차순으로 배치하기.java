import java.util.*;

class Solution {
    public long solution(long n) {
        long answer = 0;
        
        String str = Long.toString(n);
        
        List<Character> chars = new ArrayList<Character>();
        for(int i=0; i<str.length(); i++){
            chars.add(str.charAt(i));
        }
        
        chars.sort(Comparator.reverseOrder());
        
        String answerStr = "";
        for(int i=0; i<chars.size(); i++){
            answerStr += chars.get(i);
        }
        
        answer = Long.parseLong(answerStr);
        
        return answer;
    }
}