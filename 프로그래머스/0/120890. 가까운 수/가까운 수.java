import java.util.*;

class Solution {
    public int solution(int[] array, int n) {
        int answer = 0;
        int min = 100; 
        Arrays.sort(array);
        for(var num : array){
            if(Math.abs(n-num)<min){
                min = Math.abs(n-num);
                answer = num;
            }
        }
        return answer;
    }
}