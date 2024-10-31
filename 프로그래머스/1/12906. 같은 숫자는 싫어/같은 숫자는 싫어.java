import java.util.*;

public class Solution {
    
    public static final int MAX_INT = 1000000; 
    
    public int[] solution(int []arr) {
        int[] answer = {};
        int[] result = new int[MAX_INT]; 
        int cnt =0; 
        Stack<Integer> s = new Stack<>(); 
        for(int i=0; i<arr.length; i++){
            if(s.isEmpty()||s.peek()!=arr[i]){
                s.push(arr[i]); 
                result[cnt]=arr[i];
                cnt++;
            }
        }
        
        answer = new int[cnt];
        for(int i=0; i<answer.length; i++){
            answer[i] = result[i]; 
        }
        
        
        return answer;
    }
}