import java.util.*;

class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        
        Arrays.sort(people);
        
        int max = people.length-1; 
        int min = 0;
        int cnt =0; 
        
        while(min<max){
            if((people[min]+people[max])>limit){ //동반 탑승 불가
                answer++;
                max--;
                cnt++; 
            }else{ //동반 탑승
                answer++;
                max--;
                min++;
                cnt += 2; 
            }
        }
        
        if(cnt<people.length){
            answer++;
        }
        
        return answer;
    }
}