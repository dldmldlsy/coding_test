import java.util.*;

public class Main {
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
    
        int n = sc.nextInt();
        int[] len = new int[n-1];
        int[] price = new int[n];
    
        for(int i=0; i<n-1; i++){
            len[i] = sc.nextInt();
        }
        for(int i=0; i<n; i++){
            price[i] = sc.nextInt();
        }
    
        int minPrice = price[0];
        long totalPrice = 0; 
    
        for(int i=0; i<n-1; i++){
            if(minPrice>price[i]){
                minPrice = price[i];
            }
            totalPrice += minPrice*(long)len[i];
        }
    
        System.out.println(totalPrice);
    }
}