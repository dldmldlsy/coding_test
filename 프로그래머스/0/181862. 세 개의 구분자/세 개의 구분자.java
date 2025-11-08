import java.util.*;

class Solution {
    public String[] solution(String myStr) {
        String[] answer = {};
        String str = "";
        ArrayList<String> list = new ArrayList<>();
        for(int i=0; i<myStr.length(); i++){
            if(myStr.charAt(i)!='a'&&myStr.charAt(i)!='b'&&myStr.charAt(i)!='c'){
                str+=myStr.charAt(i);
            }else{
                if(!str.equals("")){
                    list.add(str);
                    str="";
                }
                continue;
            }
        }
        
        if(!str.equals("")){
            list.add(str);
        }
        
        answer = new String[list.size()];
        
        for(int i=0; i<list.size(); i++){
            answer[i] = list.get(i);
        }
        
        if(answer.length==0){
            answer = new String[1];
            answer[0] = "EMPTY";
        }
        
        return answer;
    }
}