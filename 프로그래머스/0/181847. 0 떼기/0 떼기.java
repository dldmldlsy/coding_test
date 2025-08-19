class Solution {
    public String solution(String n_str) {
        String answer = "";
        boolean ok = false;
        for(char c : n_str.toCharArray()){
            if(c!='0'){
                ok = true;
            }
            if(ok){
                answer += c;
            }
        }
        return answer;
    }
}