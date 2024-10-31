class Solution {
    public String solution(String s, int n) {
        String answer = "";
        //문자로 숫자를 바로 알고, 숫자로 문자를 바로 알 수 있게 짜야 함 ! 
        //소문자 배열: 소문자: 97~, arr[문자아스키코드값 - 97] = 문자 아스키코드값 ! 
        //대문자 배열: 대문자: 65~ , arr[문자 아스키코드값 - 65] = 문자 아스키코드값! 
        int[] small = new int[26]; 
        int[] big = new int[26];
        for(int i=0; i<26; i++){
            small[i] = i+97; 
        }
        for(int i=0; i<26; i++){
            big[i] = i+65; 
        }
        
        for(int i=0; i<s.length(); i++){
            char c = s.charAt(i);
            int idx=0; 
            //대소문자 구분
            if(Character.isLowerCase(c)){
                idx = c-97+n;  
                if(idx>25){ //범위 초과 고려
                    idx=idx-26; 
                }
                answer += (char) small[idx]; 
            }else if(Character.isUpperCase(c)){
                idx = c-65+n;
                if(idx>25){ //범위 초과 고려
                    idx = idx-26; 
                }
                answer += (char) big[idx];
            }else{
                answer += " ";
            }
        }
        
        return answer;
    }
}