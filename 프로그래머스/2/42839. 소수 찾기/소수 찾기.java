import java.util.*;

class Solution {
    //문자열 크기만큼 false로 초기화
    boolean visited[] = new boolean[7];
    //중복없이 가능한 숫자들 넣을 set 
    Set<Integer> set = new HashSet<>();     
    
    public int solution(String numbers) {
        int answer = 0;
        for(int i=0 ;i<numbers.length(); i++){
            if(numbers.charAt(i)=='0') continue;
            dfs(i, "", numbers); 
            visited[i] = false; 
        }
        
        boolean sosu = true; 
        for(Integer num : set) {
            sosu = true;
            
            if(num==1||num==0){
                continue;
            }
            for(int i=2; i<=num-1; i++){
                if(num%i==0){
                    sosu = false;
                    break;
                }
            }
            
            if(sosu) {
                answer++;}
        }
        return answer;
    }
    
    public void dfs(int n, String str, String numbers){
        if(visited[n]){
            return;
        }
        
        visited[n] = true;
        str += numbers.charAt(n);
        set.add(Integer.parseInt(str));
      
        for(int i=0; i<numbers.length(); i++){
            if(!visited[i]){
                dfs(i, str, numbers);
                visited[i] = false;
            }
        }
    }
    
}