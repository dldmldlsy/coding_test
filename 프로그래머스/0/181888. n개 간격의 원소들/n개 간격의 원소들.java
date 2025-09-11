class Solution {
    public int[] solution(int[] num_list, int n) {
        int[] answer = {};

        int size = (num_list.length%n==0) ? num_list.length/n : num_list.length/n+1;

        answer = new int[size];
        int idx = 0;
        for(int i=0; i<num_list.length; i=i+n){
            answer[idx++] = num_list[i];
        }
        return answer;
    }
}