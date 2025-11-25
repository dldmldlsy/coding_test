import java.util.*;

class Solution {
    public int[] solution(String my_string) {
        int[] answer = {};
        ArrayList<Integer> list = new ArrayList<>();
        
        for(char c : my_string.toCharArray()){
            if(Character.isDigit(c)){
                list.add(c-'0');
            }
        }
        answer = new int[list.size()];
        int idx = 0;
        for(int i : list){
            answer[idx++] = i;
        }
        Arrays.sort(answer);
        return answer;
    }
}