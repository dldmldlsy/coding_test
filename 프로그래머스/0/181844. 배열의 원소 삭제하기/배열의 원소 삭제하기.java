import java.util.*;

class Solution {
    public int[] solution(int[] arr, int[] delete_list) {
        int[] answer = {};
        ArrayList<Integer> answerlist = new ArrayList<>();
        boolean delete = false; 
        for(int i=0; i<arr.length; i++){
            delete = false;
            for(int j=0; j<delete_list.length; j++){
                if(arr[i]==delete_list[j]){
                    delete = true;
                }
            }
            if(!delete){
                answerlist.add(arr[i]);
            }
        }
        
        answer = new int[answerlist.size()];
        
        for(int i=0; i<answerlist.size(); i++){
            answer[i] = answerlist.get(i);
        }
        return answer;
    }
}