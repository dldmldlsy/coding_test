class Solution {
    public int solution(int a, int b, int c) {
        int answer = 0;
        
        if(a!=b&&b!=c&&c!=a){
            answer = a+b+c;
        }else if (a==b&&b==c){
            answer = (int) ((a+b+c)*(Math.pow(a, 2)+Math.pow(b, 2)+Math.pow(c, 2))*(Math.pow(a, 3)+Math.pow(b, 3)+Math.pow(c, 3)));
        }else{
            answer = (int)((a+b+c)*(Math.pow(a, 2)+Math.pow(b, 2)+Math.pow(c, 2)));
        }
        return answer;
    }
}