class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2]; // 가로, 세로 길이
                
        int size = brown + yellow; 
        
        //가로 x, 세로y의 범위: 최소 3, 최대 size/3 (전체크기/최소인 경우 = 최대)
        
        for(int x=3; x<=size/3; x++){
            for(int y=3; y<=size/3; y++){
                if(x*y==size&& (x+y)==brown/2+2 && x>=y){
                    answer[0] = x; 
                    answer[1] = y; 
                    return answer;
                }
            }
        }
        return answer;
    }
}