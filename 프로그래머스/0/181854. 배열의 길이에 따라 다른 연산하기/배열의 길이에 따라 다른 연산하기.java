class Solution {
    public int[] solution(int[] arr, int n) {
        int[] answer = {};
        if(arr.length%2==1){
            for(int i=0; i<arr.length; i=i+2){
                arr[i] += n;
            }
        }else{
            for(int i=1; i<arr.length; i=i+2){
                arr[i] += n;
            }
        }
        answer= arr;
        return answer;
    }
}