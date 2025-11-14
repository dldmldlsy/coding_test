class Solution {
    public String solution(String my_string, int[][] queries) {
        String answer = "";
        for(int i=0; i<queries.length; i++){
            int start = queries[i][0];
            int end = queries[i][1];
            String str = my_string.substring(start, end+1);
            StringBuffer sb = new StringBuffer(str);
            String rev = sb.reverse().toString();
            my_string = my_string.substring(0, start) + rev + my_string.substring(end+1);
        }
        
        answer = my_string;
        return answer;
    }
}