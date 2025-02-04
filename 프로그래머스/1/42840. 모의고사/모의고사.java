import java.util.Arrays;

class Solution {
    public int[] solution(int[] answers) {
        int[] answer = {};
        
        int problems = answers.length; //문제수
        
        int[] first = new int[problems];
        int[] second = new int[problems];
        int[] third = new int[problems];
        
        for(int i=1; i<=problems; i++){
            if(i%5 == 0){
                first[i-1] = 5; 
            }else {
                first[i-1] = i%5; 
            }
            
            
            if(i%2==1){
                second[i-1] = 2; 
            }else if(i%8==2){
                second[i-1] = 1; 
            }else if(i%8==4){
                second[i-1] = 3; 
            }else if(i%8==6){
                second[i-1] = 4;
            }else if(i%8==0){
                second[i-1] = 5;
            }
            
            int v = i%10;
            if(i%10==1||i%10==2){
                third[i-1] = 3; 
            }else if(v == 3||v ==4){
                third[i-1] =1;
            }else if(v == 5|| v==6){
                third[i-1]=2; 
            }else if(v==7||v==8){
                third[i-1]=4;
            }else if(v==9||v==0){
                third[i-1]=5;
            }
        }
        
        int cntf = 0; 
        int cnts = 0; 
        int cntt = 0; 
        int correct =0; 
        for(int i=0 ;i<problems; i++){
            correct = answers[i];
            
            if(first[i]==correct){
                cntf++;
            }
            if(second[i]==correct){
                cnts++;
            }
            if(third[i] == correct){
                cntt++;
            }
        }
        
        int[] score = new int[]{cntf, cnts, cntt}; 
        
        int max = Math.max(cntf, Math.max(cnts, cntt)); 
        
        int cnt = 0;
        for(int i=0; i<score.length; i++){
            if(score[i]==max){
                cnt++;
            }
        }
        
        answer = new int[cnt];
        int idx = 0; 
        for(int i=0; i<score.length; i++){
           // System.out.println(score[i]);
            if(score[i]==max){
                answer[idx++] = i+1; 
            }
        }
        
        Arrays.sort(answer);
        return answer;
    }
}