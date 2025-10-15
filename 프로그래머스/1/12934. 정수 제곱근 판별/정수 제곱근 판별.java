class Solution {
    public long solution(long n) {
        long answer = 0;
        double sn = Math.sqrt(n);
        double x = sn%(double)1;
        if(x>0){
            answer = -1;
        }else{
            answer = (long)(sn+1)*(long)(sn+1);
        }
        return answer;
    }
}