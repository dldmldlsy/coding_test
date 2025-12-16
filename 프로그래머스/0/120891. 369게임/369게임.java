class Solution {
    public int solution(int order) {
        int answer = 0;
        String str = Integer.toString(order);
        for(int i=0; i<str.length(); i++){
            int now = str.charAt(i)-'0';
            if(now==3||now==6||now==9){
                answer++;
            }
        }
        return answer;
    }
}