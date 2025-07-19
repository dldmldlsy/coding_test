import java.util.*;

class Solution {
    int answer = 0;
    public int solution(String begin, String target, String[] words) {
        int answer = bfs(begin, target, words);
        
        return answer;
    }
    
    int bfs(String start, String goal, String[] words){
        boolean existTarget = false;
        for(int i=0; i<words.length; i++){
            if(words[i].equals(goal)){
                existTarget = true;
            }
        }
        if(!existTarget) {
            return 0;
        }
        Queue<String> q = new LinkedList<>();

        q.add(start);

        int cnt =0;
        boolean end = false;
        boolean nextWord = false;
        while(!end){
            String str ="";
            int size = q.size();
            while(size-->0){
                str = q.remove();
                if(str.equals(goal)){
                    end = true;
                    break;
                }
                nextWord = false;
                for(int i=0; i<words.length; i++){
                    String next = words[i];
                    int diff = 0;
                    for(int j=0; j<next.length(); j++){
                        if(str.charAt(j)!=next.charAt(j)){
                            diff++;
                        }
                    }
                    if(diff==1){
                        q.add(next);
                        nextWord = true;
                    }
                }
            }
            if(!end){
                if(!nextWord){
                    end = true;
                    cnt = 0;
                    break;
                }else{
                    cnt++;
                }
            }
        }
        return cnt;
    }
}

