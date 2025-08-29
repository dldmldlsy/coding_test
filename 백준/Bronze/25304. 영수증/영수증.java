import java.io.*;

public class Main{
    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int x = Integer.parseInt(br.readLine());
        int n = Integer.parseInt(br.readLine());
        int sum = 0;
        
        for(int i=0; i<n; i++){
            String[] strs = br.readLine().split(" ");
            int a = Integer.parseInt(strs[0]);
            int b = Integer.parseInt(strs[1]);
            
            sum += a*b;
        }
        
        if(x==sum){
            System.out.print("Yes");
        }else{
            System.out.print("No");
        }
        
    }
}