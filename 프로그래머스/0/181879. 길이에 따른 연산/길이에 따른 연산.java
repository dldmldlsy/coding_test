class Solution {
    public int solution(int[] num_list) {
        int answer = (num_list.length>=11) ? 0 : 1;
        
        int len = num_list.length; 
        
        for(int i=0; i<len; i++){
            if(len>=11){
                answer+=num_list[i];
            }else{
                answer*=num_list[i];
            }
        }
          
        return answer;
    }
}