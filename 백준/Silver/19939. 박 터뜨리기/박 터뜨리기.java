import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int k = sc.nextInt();
        
        int min = k*(k+1)/2; 
        
        if(n<min){
            System.out.println(-1);
            return;
        }
        
        int start = (n - k*(k-1)/2)/k;
        
        int used = start*k + k*(k-1)/2;
        
        int remain = n - used;
        
        int[] barget = new int[k];
        
        for(int i=0; i<k; i++){
            barget[i] = start+i;
        }
        int idx = k-1; 
        for(int i=0; i<remain; i++){
            barget[idx]++;
            if(idx==0){
                idx= k-1;
            }else {
                idx--;
            }
        }
        
        System.out.println(barget[k-1]-barget[0]);
    }
}