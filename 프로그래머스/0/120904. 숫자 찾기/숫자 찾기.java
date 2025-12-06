class Solution {
    public int solution(int num, int k) {
        int answer = -1;
        String str = Integer.toString(num);
        
        if(str.contains(Integer.toString(k))){
            answer = str.indexOf(k+'0') + 1 ;
        }
        
        return answer;
    }
}