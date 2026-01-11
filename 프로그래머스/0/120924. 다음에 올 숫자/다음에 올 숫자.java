class Solution {
    public int solution(int[] common) {
        int answer = 0;
        int size = common.length;
        int first = common[0];
        int sec = common[1];
        int thrd = common[2];
        if(thrd-sec==sec-first){
            answer = common[size-1]+thrd-sec;
        }else{
            answer = common[size-1]*thrd/sec;
        }
        return answer;
    }
}