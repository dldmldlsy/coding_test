/*
규칙에 맞는 아이디 추천해주는 프로그램 

[아이디 규칙]
- 아이디 길이 3 이상 15 이하
- 소문자, 숫자, -, _, . 만 사용 가능
- .는 처음과 끝 및 연속 사용불가
[신규 아이디 추천 방법]
1. 모든 대문자를 소문자로 치환
2. 소문자, 숫자, -, _, . 빼고 다 제거
3. .가 2번 연속 있으면 1번으로 치환
4. .가 처음이나 끝에 위치하면 제거
5. 빈 문자열이라면, a 추가
6. 16자 이상이면 15자까지만 남기고 제거 + 맨 뒤가 .면 제거
7. 2자 이하면 길이가 3이 될 때까지 마지막 문자를 반복 추가
*/

class Solution {
    public String solution(String new_id) {
        String answer = "";
        char pc = '!'; 
        String temp = "";
        //규칙에 맞는 추천 아이디로 변경
        for(char c : new_id.toCharArray()){
            //1. 소문자로 치환
            if(Character.isUpperCase(c)){
                c = (char) (c + 32); 
            }
            //2. 구성 요소 확인
            if(Character.isDigit(c)||Character.isAlphabetic(c)||c=='-'||c=='_'||c=='.'){
                temp += c;
            }
        }
        
        //3. 현재 문자와 이전 문자가 모두 .면 (= .가 연속이면 미포함)
        for(char c: temp.toCharArray()){
            if(c=='.'&&pc=='.'){
                continue;
            }
            answer += c;
            pc = c;
        }
        
        //4. .가 처음이나 끝에 위치하면 제거 
        if(!answer.isEmpty()&&answer.charAt(0)=='.') {
            answer = answer.substring(1); 
        }
        if(!answer.isEmpty()&&answer.charAt(answer.length()-1)=='.'){
            answer = answer.substring(0, answer.length()-1);
        }
        
        //5. 빈문자열이면 a 추가
        if(answer.equals("")){
            answer = "a"; 
        }
        
        //6. 16자 이상이면 15까지 자르고 맨 뒤가 .이면 제거
        if(answer.length()>15){
            answer = answer.substring(0, 15);
        }
        if(answer.charAt(answer.length()-1)=='.'){
            answer = answer.substring(0, answer.length()-1);
        }
        //7. 2자 이하이면 길이가 3 될 때까지 맨 마지막 문자 추가
        if(answer.length()<3){
            char lc = answer.charAt(answer.length()-1); 
            
            while(answer.length()!=3){
                answer += lc;
            }
        }
        
        return answer;
    }
}