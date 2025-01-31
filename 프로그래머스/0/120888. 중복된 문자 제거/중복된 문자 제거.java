class Solution {
    public String solution(String my_string) {
        String answer = "";
        
        int[] arr = new int[125]; 
        
        for(char c : my_string.toCharArray()){
            if(arr[(int)c]==0){
                arr[(int)c] = 1; 
                answer += c; 
            }else{
                continue;
            }
        }
        return answer;
    }
}