class Solution {
    public int solution(int[] array) {
        int answer = -1;
        int[] arr = new int[1001];
        
        for(int i=0; i<array.length; i++){
            arr[array[i]]++;
        }
        int max = 0;
        for(int i=0; i<arr.length; i++){
            if(arr[i]>max){
                max = arr[i];
                answer=i;
            }
        }
        int cnt = 0;
        for(int i=0; i<arr.length; i++){
            if(arr[i]==max){
                cnt++;
            }
        }
        if(cnt>1){
            answer=-1;
        }
        return answer;
    }
}