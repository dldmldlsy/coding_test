class Solution {
    public String solution(int age) {
        String answer = "";
        String str = Integer.toString(age);
        for(int i=0; i<str.length(); i++){
            int n = str.charAt(i)-'0';
            answer += (char) ('a'+n);
        }
        return answer;
    }
}