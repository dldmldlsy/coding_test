class Solution {
    public int solution(String myString, String pat) {
        int answer = 0;
        System.out.println(myString);
        myString = myString.replace("A", "C"); 
        myString = myString.replace("B", "A");
        myString = myString.replace("C", "B");
        if(myString.contains(pat)){
            answer = 1;
        }
        return answer;
    }
}