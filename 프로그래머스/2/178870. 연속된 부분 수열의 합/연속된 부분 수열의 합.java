class Solution {
    public int[] solution(int[] sequence, int k) {
        int[] answer = {};
        
        answer = new int[2];
        
        int len = sequence.length+1; ; // 부분배열 길이
        int start = 0, end = 0;
        int sum; 
        sum = sequence[start];
        while(end<sequence.length&&start<=end){
            //System.out.println(sum+" "+k);
            if(sum<k){
                end++; 
                if(end==sequence.length) break;
                sum+=sequence[end];
            }else if(sum>k){
                sum-=sequence[start];
                start++;
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
                end++;
                if(end==sequence.length) break;
                sum+=sequence[end];
            }
        }
        return answer;
    }
}