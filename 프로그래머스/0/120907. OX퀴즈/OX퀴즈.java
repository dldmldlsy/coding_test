class Solution {
    public String[] solution(String[] quiz) {
        String[] answer = {};
        answer = new String[quiz.length];
        int tmp=-30000;
        for(int i=0; i<quiz.length; i++){
            String[] strs = quiz[i].split(" ");
            if(strs[1].equals("-")){
                tmp = Integer.parseInt(strs[0])-Integer.parseInt(strs[2]);
            }else if(strs[1].equals("+")){
                tmp = Integer.parseInt(strs[0])+Integer.parseInt(strs[2]);
            }
            
            if(tmp==Integer.parseInt(strs[4])){
                answer[i]="O";
            }else{
                answer[i]="X";     
            }
        }
        return answer;
    }
}