class Solution {
    public int solution(int[] num_list) {
        int answer = 0; 
        int num;
        for(int i=0; i<num_list.length; i++){
            num = num_list[i];
            while(num!=1){
                if(num%2==1){
                    num--; 
                }
                num /= 2;
                answer++;
            }
        }
        return answer;
    }
}