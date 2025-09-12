class Solution {
    public String solution(String phone_number) {
        String answer = "";
        String pre = "*".repeat(phone_number.length()-4);
        
        answer += pre;
        answer += phone_number.substring(phone_number.length()-4);
        
        return answer;
    }
}