import java.util.Arrays;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = {};
        
        answer = new int[commands.length];
        for(int i=0; i<commands.length; i++){
            int startidx = commands[i][0];
            int endidx = commands[i][1];
            int k = commands[i][2];
            
            int[] arr = Arrays.copyOfRange(array, startidx-1, endidx);
            Arrays.sort(arr);
            answer[i] = arr[k-1];
        }
        return answer;
    }
}