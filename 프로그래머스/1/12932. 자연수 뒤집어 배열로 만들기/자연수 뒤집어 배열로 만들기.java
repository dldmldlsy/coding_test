class Solution {
    public int[] solution(long n) {
        int[] answer = {};
        String str = Long.toString(n); 
        StringBuilder sb = new StringBuilder(); 
        sb.append(str); 
        sb.reverse(); 
        String reverseStr = sb.toString(); 
        answer = new int[reverseStr.length()]; 
        System.out.println(reverseStr);
        for(int i=0; i<answer.length; i++){
            //answer[i] = reverseStr.charAt(i); // char형이라 아스키코드 값이 입력됨. 정수형으로 바꿔줘야 함.
            answer[i] = reverseStr.charAt(i)-'0';
        }
        return answer;
    }
}