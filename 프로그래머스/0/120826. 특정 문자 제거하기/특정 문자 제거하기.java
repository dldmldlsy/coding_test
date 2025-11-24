class Solution {
    public String solution(String my_string, String letter) {
        String answer = "";
        for(char c : my_string.toCharArray()){
            if(!Character.toString(c).equals(letter)){
                answer+=c;
            }
        }
        return answer;
    }
}