class Solution {
    public int solution(String[] babbling) {
        int answer = 0;
        String[] words = {"aya", "ye", "woo", "ma"};
        boolean possible = false;
        //각 단어별로 발음여부 파악하기
        
        for(int idx = 0; idx<babbling.length; idx++){
            String str = babbling[idx]; //가능한지 확인해야하는 단어
            possible = false;
            String word; 
            String pre = "";            
            while(str.length()>0){
                possible = false;
                for(int i=0; i<words.length; i++){ //가능한 발음
                    word = words[i];
                    if(str.length()<word.length()){
                        continue;
                    }
                    if(str.substring(0, word.length()).equals(word)){
                        if(!pre.equals(word)){
                            possible = true;
                            pre = word;
                            if(str.length()-word.length()==0){
                                str = "";
                                break;
                            }else{
                                str = str.substring(word.length());
                            }
                            break;
                        }
                    }
                }
                if(!possible){
                    break;
                }
            }
            
            if(possible){
               answer++; 
            }
        }
        
        return answer;
    }
}