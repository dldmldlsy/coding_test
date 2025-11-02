class Solution {
    public String solution(int a, int b) {
        String answer = "";
        int total=0;
        int[] year = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i=1; i<a; i++){
            total+=year[i];
        }
        total += b;
        total--;
        if(total%7==0){
            answer="FRI";
        }else if(total%7==1){
            answer="SAT";
        }else if(total%7==2){
            answer ="SUN";
        }else if(total%7==3){
            answer="MON";
        }else if(total%7==4){
            answer="TUE";
        }else if(total%7==5){
            answer="WED";
        }else if(total%7==6){
            answer="THU";
        }
            
        return answer;
    }
}