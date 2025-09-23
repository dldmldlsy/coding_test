class Solution {
    public int[] solution(int n, int m) {
        int[] answer = {};
        int a = Math.max(n, m); 
        int b = Math.min(n, m);
        int tmp, gcd;
        while(true){
            if(a%b==0){
                gcd = b; break;
            }
            tmp = b;
            b = a%b; 
            a = tmp; 
        }
        
        int lcm = n*m/gcd;
        
        answer = new int[2];
        
        answer[0] = gcd;
        answer[1] = lcm;
        return answer;
    }
}