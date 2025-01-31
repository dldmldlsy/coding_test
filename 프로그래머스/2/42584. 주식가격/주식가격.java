import java.util.Stack;

class Solution {
    public int[] solution(int[] prices) {
        int[] answer = {};
        
        answer = new int[prices.length];
        
        Stack<Integer> stack = new Stack<>();
        
        for(int i=0; i<prices.length; i++){
            if(stack.isEmpty()){
                stack.push(i);     
            }else{
                while(true){
                    if(stack.isEmpty()){
                        stack.push(i); 
                        break;
                    }
                    int top = stack.peek(); 
                    if(prices[top]<=prices[i]){
                        stack.push(i);
                        break;
                    }
                    answer[top] = i-top;
                    stack.pop(); 
                }
            }
        }
        
        while(!stack.isEmpty()){
            int top = stack.peek(); 
            answer[top] = (prices.length-1) - top;
            stack.pop();
        }
        
        return answer;
    }
}