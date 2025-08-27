import java.util.*;

class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        
        Arrays.sort(citations);
        
        int left = 0; 
        int right = citations.length;
        
        while(left<=right){
            int mid = (left+right)/2; 
            
            //lowerbound 구하기
            int idx = lowerBound(citations, mid);
            int cnt = citations.length-idx;
            
            if(cnt>=mid){
                answer = mid;
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return answer;
    }
    
    int lowerBound(int[] a, int value){
        int l = 0, r = a.length;
        while (l < r) {
            int m = l + (r - l) / 2;  
            if (a[m] >= value) r = m;
            else l = m + 1;
        }
        return l;
    }
}