import java.util.*;

class Solution {
    public String solution(int[] numbers, String hand) {
        String answer = "";
        Set<Integer> setleft = Set.of(1, 4, 7); 
        Set<Integer> setright = Set.of(3, 6, 9);
        int nowleft = 10; 
        int nowright = 12; 
        int goal = 0; 
        int lr, lc; 
        int rr, rc; 
        int gr, gc; 
        for(int number: numbers){
            if(number==0){
                number = 11; 
            }
            if(setleft.contains(number)){
                answer += "L";
                nowleft = number;
            }else if (setright.contains(number)){
                answer+="R";
                nowright = number;
            }else {
                goal = number;
                gc = goal%3; if(gc==0) gc=3;
                gr = (goal-gc)/3; 
                
                lc = nowleft%3; if(lc==0) lc = 3;
                lr = (nowleft-lc)/3; 
                
                rc = nowright%3; if(rc==0) rc = 3; 
                rr = (nowright-rc)/3; 
                
                int disleft = Math.abs(gr-lr)+Math.abs(gc-lc); 
                int disright = Math.abs(gr-rr)+Math.abs(gc-rc);
                //System.out.println(number+": "+nowleft+" "+nowright+", "+disleft+" "+disright + ":: "+gr+gc+rr+rc);
                //if(number==11){}
                if(disleft<disright){
                    answer+="L";
                    nowleft= number;
                }else if(disright<disleft){
                    answer+="R";
                    nowright = number;
                }else{
                    if(hand.equals("left")){
                        answer+="L";
                        nowleft= number;
                    }else if(hand.equals("right")){
                        answer+="R";
                        nowright = number;
                    }
                }
            }
        }
        
        
        return answer;
    }
}