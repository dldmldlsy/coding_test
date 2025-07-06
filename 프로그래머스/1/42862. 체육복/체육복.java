import java.util.*;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        
        int[] arr = new int[n+1];
        
        Arrays.sort(lost);
        
        for(int i=0; i<reserve.length; i++){
            arr[reserve[i]] = 1;
        }
        
        int get=0;
        int num = 0; 
        for(int i=0 ;i<lost.length; i++){
            num = lost[i];
            if(arr[num]==1){
                arr[num]=-1;
                get++;
            }
        }
        for(int i=0; i<lost.length; i++){
            num = lost[i];
            if(arr[num]==-1){
                continue;
            }else if(num-1>=1&&arr[num-1]==1){
                arr[num-1]=0;
                get++;
            }else if(num+1<=n&&arr[num+1]==1){
                arr[num+1]=0;
                get++;
            }
        }
        answer = n-lost.length+get;
        return answer;
    }
}