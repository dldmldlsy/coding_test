import java.util.*;

class Solution {
    public int solution(int[][] sizes) {
        int answer = 0;
        int max = 0; 
        int side = 0; 
        for(int i=0; i<sizes.length; i++){
            if(max<sizes[i][0]){
                max = sizes[i][0];
                side = 0;
            }else if(max<sizes[i][1]){
                max = sizes[i][1];
                side = 1;
            }
        }
        int tmp = 0;
        int max2 = 0; 
         for(int i=0; i<sizes.length; i++){
            if(side == 0){
                if(sizes[i][1]>sizes[i][0]){
                    max2 = Math.max(max2, sizes[i][0]);
                }else {
                    max2 = Math.max(max2, sizes[i][1]);
                }
            }else if(side == 1){
                if(sizes[i][0]>sizes[i][1]){
                    max2 = Math.max(max2, sizes[i][1]);
                }else {
                    max2 = Math.max(max2, sizes[i][0]);
                }
            }
        }
        
        answer = max*max2;
        
        
        
        return answer;
    }
}