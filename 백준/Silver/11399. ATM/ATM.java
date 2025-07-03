import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int[] times = new int[n];
        
        for(int i=0; i<n; i++){
            times[i] = sc.nextInt();
        }
        
        Arrays.sort(times);

        int sum =0; 
        int total = 0; 
        for(int i=0; i<n; i++){
            sum += times[i];
            total += sum;
        }
        
        System.out.println(total);
    }
}