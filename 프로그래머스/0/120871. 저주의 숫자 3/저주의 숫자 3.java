class Solution {
    public int solution(int n) {
        int answer = 1;
        int cnt = 0;
        while(cnt<n){
            if(answer%3==0){
                answer++;
                continue;
            }else if(Integer.toString(answer).contains("3")){
                answer++;
                continue;
            }else{
                cnt++;
                if(cnt==n){
                    break;
                }
                answer++;
            }
        }
        return answer;
    }
}