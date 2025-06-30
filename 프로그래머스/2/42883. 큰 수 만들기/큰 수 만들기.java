import java.util.*;

class Solution {
    public String solution(String number, int k) {
        String answer = "";
        Stack<Integer> st = new Stack<Integer>();
        int cnt = 0;
        int now = 0; 
        
            for(int i=0; i<number.length(); i++){
                now = number.charAt(i)-'0';
                
                while(!st.isEmpty()&& st.peek()<now&& cnt<k){
                    st.pop();
                    cnt++;
                }
                st.push(now);
            
            }
        
        while(cnt<k){
            st.pop();
            cnt++;
        }
    
        
        while(!st.isEmpty()){
            answer += st.pop();
        }
         
        
        return new StringBuilder(answer).reverse().toString();
    }
}