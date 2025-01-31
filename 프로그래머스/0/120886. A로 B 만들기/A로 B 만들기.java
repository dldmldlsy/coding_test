class Solution {
    public int solution(String before, String after) {
        int answer = 0;
        boolean possible = true;
        int[] arr = new int[26]; 
        for(char c: before.toCharArray()){
            arr[c-97]++; 
        }
        int[] arr2 = new int[26]; 
        for(char c: after.toCharArray()){
            arr2[c-97]++; 
        }
        for(int i=0 ;i<26; i++){
            if(arr[i]!=arr2[i]){
                possible = false;
                break;
            }
        }
        
        if(possible){answer = 1;}
        else {answer = 0;}
        return answer;
    }
}