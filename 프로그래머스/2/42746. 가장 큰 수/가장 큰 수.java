import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        String[] strs = new String[numbers.length];
         
        for(int i = 0; i<numbers.length; i++){
            strs[i] = Integer.toString(numbers[i]);
        }
        //정렬
        Arrays.sort(strs, (s1, s2)-> {
               return (s2+s1).compareTo(s1+s2);
        });
        
        if(strs[0].equals("0")) {
            answer = "0"; 
        }else{
            for(String str : strs){
                answer += str;
            }
        }
        
        return answer;
    }
}