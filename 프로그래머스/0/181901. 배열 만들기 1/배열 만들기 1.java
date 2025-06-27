class Solution {
    public int[] solution(int n, int k) {
        int[] answer = {};
        
        int size = n/k; 
        
        answer = new int[size];
        for(int i=1; i<=size; i++){
            answer[i-1] = i*k;
        }
        
        return answer;
    }
}