import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt(); 
        
        while(t>0){
            int n = sc.nextInt(); 
            int[] prices = new int[n];
            
            for(int i=0; i<n; i++){
                prices[i] = sc.nextInt();
            }
            
            int max = prices[n-1]; 
            int now = 0; 
            long profit = 0; 
            for(int i=n-2; i>=0; i--){
                now = prices[i];
                if(max>now){
                    profit += max-now; 
                }else if (max<now){
                    max = now;
                }
            }
            
            System.out.println(profit);
            t--;
        }
    }
}