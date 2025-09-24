class Solution {
    public boolean solution(int x) {
        boolean answer = true;
        int sum=0;
        int num = x;
        int len = Integer.toString(x).length();
        for(int i=1; i<=len; i++){
            sum += x%10;
            x = x/10;
        }
        if(num%sum!=0) {
            answer=false;
        }
        return answer;
    }
}