import java.util.*;

class Solution {
    public int[] solution(int[] arr) {
        int[] answer = {};
        int size = arr.length;
        
        if(size==1){
            answer = new int[1];
            answer[0] = -1;
            return answer;
        }
        
        answer = new int[size-1];
        
        int[] brr = new int[size];
        for(int i=0; i<size; i++){
            brr[i] = arr[i];
        }
        
        Arrays.sort(brr);
        int min = brr[0];
        int idx = 0;
        for(int i=0; i<size; i++){
            if(arr[i]==min){
                continue;
            }
            answer[idx++] = arr[i];
        }
        
        return answer;
    }
}