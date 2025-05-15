import java.util.*;

class Solution {
    public int solution(String skill, String[] skill_trees) {
        int answer = 0;
        Set<Character> set = new HashSet<>();
        Queue<Character> queue = new LinkedList<>();
        for(int i=0; i<skill.length(); i++){
            set.add(skill.charAt(i));
        }
        boolean possible = true;
        char sk;
        for(String skill_tree: skill_trees){
            possible = true;
             for(int i=0; i<skill.length(); i++){
                queue.offer(skill.charAt(i));
             }
            for(int i=0; i<skill_tree.length(); i++){
                sk = skill_tree.charAt(i);
                if(!set.contains(sk)){
                    continue;
                }else{
                    if(sk!=queue.peek()){
                        possible = false;
                        break;
                    }else{
                        queue.poll();
                    }
                }
            }
            if(possible){
                answer++;
            }
            queue.clear();
        }
        return answer;
    }
}