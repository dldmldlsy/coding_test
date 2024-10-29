class Solution {
    public int[] solution(int n) {
        int[] answer = {};
        int size = n*(n+1)/2; 
        int[][] dal = new int [n][]; 
        for(int i=0; i<n; i++){
            dal[i] = new int[i+1]; 
        }
        int num = 1;
        int row = 0, col = 0; 
        
        int cnt = n; 
        while(cnt>0){
            while(row<n&&dal[row][col]==0){
                dal[row++][col] = num++; 
            }
            if(--cnt == 0) {break;}
            
            row--; 
            col++; 
            while(col<n&&dal[row][col]==0){
                dal[row][col++] = num++; 
            }
            if(--cnt == 0) {break;}

            col--; 
            row--; col--; 
            while(row>=0&&col>=0&&dal[row][col]==0){
                dal[row--][col--]=num++;
            }
            row++; col++;
            row++;
            if(--cnt == 0) {break;}
        }
        
        answer = new int[size];
        int idx = 0; 
        for(int i=0; i<n; i++){
            for(int j=0; j<dal[i].length; j++){
                answer[idx] = dal[i][j];
                idx++;
            }
        }
        return answer;
    }
}