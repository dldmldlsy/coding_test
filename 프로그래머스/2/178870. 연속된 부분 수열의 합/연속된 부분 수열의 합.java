class Solution {
    public int[] solution(int[] sequence, int k) {
        int[] answer = {};
        
        answer = new int[2];
        
        int len = sequence.length+1; ; // 부분배열 길이
        int start = 0, end = 0; //두 인덱스 모두 시작점에서 출발
        int sum; // 부분 수열 합
        sum = sequence[start]; 
        while(end<sequence.length&&start<=end){
            if(sum<k){
                if(++end==sequence.length) break;
                sum+=sequence[end];
            }else if(sum>k){
                sum-=sequence[start++];
            }else{ // sum = k
                if(end-start<len){
                    len = end-start; 
                    answer[0] = start;
                    answer[1] = end;
                }else if(end-start==len){
                    if(start<answer[0]){
                        answer[0] = start;
                        answer[1] = end;
                    }
                }
                //if(++end==sequence.length) break;
                sum-=sequence[start++];
            }
        }
        return answer;
    }
}