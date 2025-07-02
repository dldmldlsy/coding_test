import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        
        int[] num = new int[n];
        for(int i=0; i<n; i++){
            num[i] = sc.nextInt();
        }
        
        Arrays.sort(num);
        
        int dis = 0 ;
        int now = 0; 
        int next = 0; 
        for(int i=0; i<n; i++){
            now = num[i];
            if(i==n-1){
                next = num[0];
            }else{
                next = num[i+1];
            }
            dis += Math.abs(next-now);
        }
        
        System.out.println(dis);
    }
}