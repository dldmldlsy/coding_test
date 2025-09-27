class Solution {
    public int[] solution(int[] arr) {
        int[] answer = {};
        int left = 0; 
        int right = arr.length-1;
        boolean exist = false;
        while(left<arr.length){
            if(arr[left]==2){
                exist = true; 
                break;
            }
            left++;
        }
        while(right>=0){
            if(arr[right]==2){
                exist = true; 
                break;
            }
            right--;
        }
        
        if(!exist){
            answer = new int[1];
            answer[0] = -1;
        }else{
            answer = new int[right-left+1];
            int idx=0;
            for(int i = left; i<=right; i++){
                answer[idx++]=arr[i];
            }
        }
        
        return answer;
    }
}