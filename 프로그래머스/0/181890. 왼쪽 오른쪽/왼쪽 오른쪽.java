class Solution {
    public String[] solution(String[] str_list) {
        String[] answer = {};
        int lidx = -1;
        int ridx = -1;
        int pos = 0;
        int idx = -1;
        for(int i=0; i<str_list.length; i++){
            if(str_list[i].equals("l")&&lidx==-1){
                lidx= i;
                if(ridx==-1){
                    pos = -1;
                    idx = i;
                }
            }
            if(str_list[i].equals("r")&&ridx==-1){
                ridx = i;
                if(lidx==-1){
                    pos = 1;
                    idx=i;
                }
            }
        }
        
        if(lidx==-1&&ridx==-1){
            return answer;
        }
        
        if(pos==1){ //right
            answer = new String[str_list.length-1-idx];
            for(int i=idx+1; i<str_list.length; i++){
                answer[i-idx-1] = str_list[i];
            }
        }else if(pos==-1){//left
            answer = new String[idx]; 
            for(int i=0; i<idx; i++){
                answer[i] = str_list[i];
            }
        }
        return answer;
    }
}