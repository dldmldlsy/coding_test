import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        
        int[] leftTall = new int[n];
        
        //사람들이 기억하는 왼쪽에 있는 나보다 큰 사람 수
        for(int i=0; i<n; i++){
            leftTall[i] = sc.nextInt();
        }
        
        int[] answer = new int[n]; // 최종 줄
        
        for(int i=0; i<n; i++){
            int min = leftTall[i]; //내 왼쪽에 있는 최소 수
            int cnt = 0; 
            int idx = 0; 
            while(true){
                if(answer[idx]==0){
                    if(cnt==min){
                        break;
                    }
                    cnt++;
                }
                idx++;
            }
            answer[idx]= i+1;
        }
        for(int i=0; i<n; i++){
            System.out.print(answer[i]+" ");
        }
        
        
    }
}