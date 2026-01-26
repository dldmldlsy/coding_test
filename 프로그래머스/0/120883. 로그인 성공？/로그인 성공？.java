class Solution {
    public String solution(String[] id_pw, String[][] db) {
        String answer = "";
        String id = id_pw[0];
        String pw = id_pw[1];
        
        for(int i=0; i<db.length; i++){
            if(db[i][0].equals(id)){
                if(db[i][1].equals(pw)){
                    answer = "login";
                    break;
                }else{
                    answer = "wrong pw";
                    break;
                }
            }
        }
        if(answer.equals("")){
            answer="fail";
        }
        return answer;
    }
}