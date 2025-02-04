import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        
        Arrays.sort(phone_book);
        String cur = "";
        String next = "";
        for(int i=0; i<phone_book.length-1; i++){
            cur = phone_book[i];
            next = phone_book[i+1]; 
            if(cur.length()>next.length()) continue;
            if(cur.equals(next.substring(0, cur.length()))) {
                answer = false; 
                break;
            }
        }
        
        return answer;
    }
}