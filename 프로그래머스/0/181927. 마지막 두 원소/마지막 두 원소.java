class Solution {
    public int[] solution(int[] num_list) {
        int[] answer = {};
        int size = num_list.length;
        answer = new int[size+1];
        for(int i=0; i<size; i++){
            answer[i] = num_list[i];
        }
        answer[size] = (num_list[size-2]<num_list[size-1])? num_list[size-1]-num_list[size-2] : num_list[size-1]*2; 
        return answer;
    }
}