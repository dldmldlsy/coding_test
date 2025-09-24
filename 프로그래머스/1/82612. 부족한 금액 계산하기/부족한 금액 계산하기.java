class Solution {
    public long solution(int price, int money, int count) {
        long answer = -1;
        
        long sum =0;
    
        for(int i=1; i<=count; i++){
            sum += price*i;
        }
        
        if(sum-money>0){
            answer = sum-(long)money;
        }else{
            answer = 0;
        }
        return answer;
    }
}
/*
입력값 : 2500, 4 ,2500
기대값 : 7815624996
*/