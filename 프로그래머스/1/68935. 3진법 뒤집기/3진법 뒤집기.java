class Solution {
    public int solution(int n) {
        int answer = 0;
        
        //10진법 수 -> 3진법으로 만들기
        int moc = 0; 
        int rem = 0;
        String s = ""; 
        
        while(true){
            moc = n/3; 
            rem = n%3; 
            s += (char) (rem+'0');
            if(moc==0) break;
            n = moc; 
        }
                
        //앞뒤 뒤집기: 이미 뒤집어져있음
                
        //뒤집은 3진법 수를 10진법으로 표현하기 
        for(int i=0; i<s.length(); i++){
            answer += Math.pow(3, (s.length()-i-1))*(s.charAt(i)-'0');
        }
        return answer;
    }
}