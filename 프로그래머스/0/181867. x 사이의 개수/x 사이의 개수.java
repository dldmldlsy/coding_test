class Solution {
    public int[] solution(String myString) {
        int[] answer = {};
        String[] strs = myString.split("x");

        if(myString.charAt(myString.length()-1)=='x'){
            answer = new int[strs.length+1];
            answer[answer.length-1]=0;
        }else{
            answer = new int[strs.length];
        }
        for(int i=0; i<strs.length; i++){
            answer[i] = strs[i].length(); 
        }
        return answer;
    }
}