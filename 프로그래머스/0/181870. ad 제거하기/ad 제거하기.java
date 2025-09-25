class Solution {
    public String[] solution(String[] strArr) {
        String[] answer = {};
        int size = strArr.length;
        int cnt=0;
        for(int i=0; i<size; i++){
            if(strArr[i].contains("ad")){
                cnt++;
            }
        }
        
        answer = new String[size-cnt];
        int idx =0;
        for(int i=0; i<size; i++){
            if(!strArr[i].contains("ad")){
                answer[idx++] = strArr[i];
            }
        }
        return answer;
    }
}