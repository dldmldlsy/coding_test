class Solution {
    public String solution(int a, int b) {
        String answer = "";
        int total=0;
        int[] year = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        String[] week ={"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
        for(int i=1; i<a; i++){
            total+=year[i];
        }
        total += b-1;
        answer = week[total%7];
            
        return answer;
    }
}