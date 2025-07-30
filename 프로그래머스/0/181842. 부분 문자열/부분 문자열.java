class Solution {
    public int solution(String str1, String str2) {
        int answer = 0;
        boolean exist = false;
        String tmp = "";
        for(int i=0; i<str2.length(); i++){
            for(int j =i+1; j<=str2.length(); j++){
                tmp = "";
                if(i==str2.length()-1){
                    tmp = str2.substring(i);
                }else {
                    tmp = str2.substring(i, j);
                }
                if(tmp.equals(str1)){
                    exist = true;
                    answer = 1; 
                    break;
                }
            }
            if(exist){
                break;
            }
        }
        return answer;
    }
}