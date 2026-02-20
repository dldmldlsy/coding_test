class Solution {
    public int solution(int chicken) {
        int answer = -1;
        
        if(chicken<10){
            answer = 0;
        }else if(chicken==10){
            answer = 1;
        }else{
            chicken -=10;
            answer = 1;
            answer += chicken/9;
        }
        return answer;
    }
}