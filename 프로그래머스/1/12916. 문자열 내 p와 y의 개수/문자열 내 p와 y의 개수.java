class Solution {
    boolean solution(String s) {
        boolean answer = true;
        int nump = 0; 
        int numy = 0;
        for(char c : s.toCharArray()){
            if(c=='p'||c=='P') nump++;
            if(c=='y'||c=='Y') numy++;
        }
        
        if(nump!=numy){
            answer = false;
        }
        
        return answer;
    }
}