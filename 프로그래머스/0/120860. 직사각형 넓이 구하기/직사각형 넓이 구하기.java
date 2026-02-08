class Solution {
    public int solution(int[][] dots) {
        int answer = 0;
        int rmax = -256; 
        int cmax = -256; 
        int rmin = 256;
        int cmin = 256;
        for(int i=0; i<dots.length; i++){
            if(rmax<dots[i][0]){
                rmax= dots[i][0];
            }
            if(rmin>dots[i][0]){
                rmin=dots[i][0];
            }
            if(cmax<dots[i][1]){
                cmax= dots[i][1];
            }
            if(cmin>dots[i][1]){
                cmin = dots[i][1];
            }
        }
        
        answer = (rmax-rmin)*(cmax-cmin);
        
        
        return answer;
    }
}