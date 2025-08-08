import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        Map<String, Integer> map = new HashMap<>();
        
        for(String partici: participant){
            map.put(partici, map.getOrDefault(partici, 0)+1);
        }
        
        for(String complet: completion){
            map.put(complet, map.get(complet)-1);
        }
        
        Iterator<Map.Entry<String, Integer>> it = map.entrySet().iterator();
        while(it.hasNext()){
            Map.Entry<String, Integer> e = it.next();
            if(e.getValue()>0){
                answer = e.getKey();
                break;
            }
        }
        
        return answer;
    }
}