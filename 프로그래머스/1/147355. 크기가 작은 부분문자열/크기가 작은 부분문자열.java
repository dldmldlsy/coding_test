class Solution {
    public int solution(String t, String p) {
        int answer = 0;
        String str = "";
        int size = p.length();
        Long pint = Long.parseLong(p);
        for(int i=0; i<=t.length()-size; i++){
            if(i==t.length()-size){
                str = t.substring(i);
            }else{
                str = t.substring(i, i+size);
            }
            
            if(Long.parseLong(str)<=pint){
                answer++;
            }
        }
        
        return answer;
    }
}