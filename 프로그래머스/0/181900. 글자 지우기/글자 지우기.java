import java.util.*;

class Solution {
    public String solution(String my_string, int[] indices) {
        String answer = "";
        Arrays.sort(indices);
        int p = 0; 
        for(int i=0; i<my_string.length(); i++){
            if(p>=indices.length){
                answer+= my_string.charAt(i);
                continue;
            }
            if(i<indices[p]){
                answer += my_string.charAt(i);
            }else if(i==indices[p]){
                p++;
                continue;
            }
        }
        return answer;
    }
}