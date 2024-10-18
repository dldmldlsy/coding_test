class Solution {
    public int[] solution(int[] num_list) {
        int[] answer = {};
        int length = num_list.length;
        answer = new int[length];
        for(int i=0; i<length; i++) {
            answer[i] = num_list[length-1-i];
        }
        return answer;
    }
}