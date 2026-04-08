import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Iterator;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        Stack<Integer> stack = new Stack<>();
        String[] strs;
        for(int i=0; i<n; i++){
            String str = br.readLine();
            if(str.charAt(0)=='1'){
                strs = str.split(" ");
                stack.push(Integer.parseInt(strs[1]));
            }else if(str.charAt(0)=='2'){
                if(!stack.isEmpty()){
                    System.out.println(stack.peek());
                    stack.pop();
                }else{
                    System.out.println(-1);
                }
            }else if(str.charAt(0)=='3'){
                System.out.println(stack.size());
            }else if(str.charAt(0)=='4'){
                if(stack.isEmpty()){
                    System.out.println(1);
                }else{
                    System.out.println(0);
                }
            }else if(str.charAt(0)=='5'){
                if(!stack.isEmpty()){
                    System.out.println(stack.peek());
                }else{
                    System.out.println(-1);
                }
            }
        }

    }
}
