class Solution {
    public String solution(int[] numLog) {
        String answer = "";
        int pre = numLog[0];
        int next = 0; 
        for(int i=1; i<numLog.length; i++){
            next = numLog[i];
            if(next-pre==1){
                answer += 'w';
            }else if(next-pre==-1){
                answer += 's';
            }else if(next-pre==10){
                answer += 'd';
            }else if(next-pre==-10){
                answer += 'a';
            }
            pre = next;
        }
        return answer;
    }
}