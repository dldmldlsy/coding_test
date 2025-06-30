class Solution {
    public int solution(String name) {
        int answer = 0;
        int charChange = 0 ;
        //각 문자 바꾸는 횟수 
        for(char c : name.toCharArray()){
            if(c=='A'){
                continue;
            }else {
                charChange += Math.min(c-'A', 'Z'+1 - c);
            }
        }
        
        //커서 이동 횟수
        int minMove = name.length()-1; //오른쪽으로 쭉 이동한 횟수
        int rightMove = 0;
        int leftMove = 0; 
        for(int i=0; i<name.length(); i++){
            int next = i+1;
            while(next<name.length() && name.charAt(next)=='A'){
                next++;
            }
            
            
            rightMove = i*2 + (name.length()-next);
            leftMove = i + (name.length()-next)*2;
            
            minMove = Math.min(minMove, Math.min(rightMove, leftMove));
        }
        
        answer = charChange + minMove;
        return answer;
    }
}