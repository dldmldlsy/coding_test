import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        int n = nums.length; 
        int pickNum = n/2; //골라야 하는 수
        
        Set<Integer> set = new HashSet<>(); 
        for(int num : nums){
            set.add(num);
        }
        
        int numTypes = set.size(); //폰켓몬 종류 수
        
        if(pickNum>= numTypes){
            answer = numTypes;
        }else {
            answer = pickNum;
        }
        return answer;
    }
}