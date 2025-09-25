import java.util.*;

class Solution {
    public String[] solution(String myString) {
        String[] answer = {};
        String[] tmp = myString.split("x");
        
        ArrayList<String> list = new ArrayList<>();
        
        for(int i=0; i<tmp.length; i++){
            if(!tmp[i].equals("")){
                list.add(tmp[i]);
            }
        }
        
        answer = list.toArray(new String[0]);
        Arrays.sort(answer);
      
        return answer;
    }
}