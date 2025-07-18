class Solution {
    int[] number; 
    int answer; 
    int goal;
    public int solution(int[] numbers, int target) {
        answer = 0;
        number = numbers;
        goal = target;
        
        dfs(-1, 0);
        
        return answer;
    }
    
    void dfs(int idx, int cur){
        if(idx+1==number.length){
            if(cur==goal){
                answer++;
            }
            return;
        }
        
        dfs(idx+1, cur+number[idx+1]);
        dfs(idx+1, cur-number[idx+1]);
    }
}