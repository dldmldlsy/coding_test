//프로그래머스: n의 배수
class Solution {
    public int solution(int num, int n) {
        int answer = 0;
        
        if(num%n==0){
            answer = 1;
        }
        
        return answer;
    }
}