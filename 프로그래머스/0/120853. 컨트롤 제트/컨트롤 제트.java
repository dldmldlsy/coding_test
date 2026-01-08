class Solution {
    public int solution(String s) {
        int answer = 0;
        String[] strs = s.split(" ");
        int pre = 0;
        for(String str : strs){
            if(str.equals("Z")){
                answer -= pre;
            }else{
                answer += Integer.parseInt(str);
                pre = Integer.parseInt(str);
            }
        }
        return answer;
    }
}