class Solution {
    public int[][] solution(int[][] arr) {
        int[][] answer = {};
        int size = Math.max(arr.length, arr[0].length);
        answer = new int[size][size];
        
        if(arr.length<arr[0].length){//열의 수가 많음
            for(int i=0; i<arr.length; i++){
                for(int j=0; j<size; j++){
                    answer[i][j] = arr[i][j];
                }
            }
            for(int i=arr.length; i<arr[0].length; i++){
                for(int j=0; j<size; j++){
                    answer[i][j] = 0; 
                }
            }
        }else{
           for(int i=0; i<arr.length; i++){
                for(int j=0; j<arr[0].length; j++){
                    answer[i][j] = arr[i][j];
                }
               
               for(int j=arr[0].length; j<size; j++){
                   answer[i][j] = 0;
               }
            }    
        }
    
        return answer;
    }
}