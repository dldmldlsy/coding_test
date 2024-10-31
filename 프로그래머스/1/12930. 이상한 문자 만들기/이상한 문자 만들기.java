/*
공백은 패스하고 카운트해서 홀짝 구분
*/
class Solution {
    public String solution(String s) {
        String answer = "";
        int cnt = 0;
        for(int i=0; i<s.length(); i++){
            char c = s.charAt(i);
            if(c==' '){ //공백이면 cnt 초기화
                answer += c;
                cnt = 0; 
            }else {
                if(cnt%2==1){ //홀수 => 소문자
                    answer += Character.toLowerCase(c);
                }else { //짝수 => 대문자
                    answer += Character.toUpperCase(c);
                }
                cnt++;
            }
        }
        return answer;
    }
}