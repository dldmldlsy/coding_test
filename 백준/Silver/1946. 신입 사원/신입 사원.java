import java.io.*;
import java.util.*;

class Main{
    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        
        while(t-- >0){
            int n = Integer.parseInt(br.readLine());
            
            int[] first = new int[n];
            int[] second = new int[n];
            
            int[][] score = new int[n][2];
            
            for(int i=0; i<n; i++){
                StringTokenizer st = new StringTokenizer(br.readLine());
                score[i][0] = Integer.parseInt(st.nextToken());
                score[i][1] = Integer.parseInt(st.nextToken());
            }
            int cnt = 1;  
            
            Arrays.sort(score, (s1, s2)-> s1[0]-s2[0]);
            int min = score[0][1];
            for(int i=1; i<n;i++){ 
                if(score[i][1]<min){
                    cnt++; 
                    min=score[i][1];
                }
            }
            
            System.out.println(cnt);
        }
    }
}