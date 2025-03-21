class Solution {
    public String solution(int[] numbers, String hand) {
        String answer = "";
        int leftnow = 10;
        int rightnow = 12; 
        int lr = 0; 
        int lc = 0; 
        int rr = 0; 
        int rc = 0; 
        int nr = 0; 
        int nc = 0; 
        for(int number: numbers){
            if(number==1||number==4||number==7){
                leftnow = number;
                answer += "L";
            }else if (number==3||number==6||number==9){
                rightnow = number;
                answer+="R";
            }else{ // 2 5 8 0
                if(number==0) {number=11;}
                lr = (int) Math.ceil((double)leftnow/3); 
                lc = leftnow - 3*(lr-1);
                
                rr = (int) Math.ceil((double)rightnow/3); 
                rc = rightnow - 3*(rr-1);
                
                nr = (int) Math.ceil((double)number/3); 
                nc = number - 3*(nr-1);
                
                int disleft = Math.abs(nr-lr) + Math.abs(nc-lc);
                int disright = Math.abs(nr-rr) + Math.abs(nc-rc);
                
                if(disleft<disright){
                    leftnow = number;
                    answer+= "L";
                }else if(disleft>disright){
                    rightnow = number;
                    answer+= "R";
                }else{
                    if(hand.equals("left")){
                        leftnow = number;
                        answer+= "L";
                    }else{
                        rightnow = number;
                        answer+= "R";   
                    }
                }
                
            }
        }
        return answer;
    }
}