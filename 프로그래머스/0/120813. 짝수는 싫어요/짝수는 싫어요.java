class Solution {
    public int[] solution(int n) {
        int[] answer = {};
        int size = (n%2==0) ? n/2 : n/2+1; 
 
        answer = new int[size];
        int idx = 0;
        for(int i=1; i<=n; i+=2){
            answer[idx++] = i;
        }
        return answer;
    }
}