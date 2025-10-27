import java.util.*;
import java.io.*;

class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String[] strs = br.readLine().split(" ");
        
        int n = Integer.parseInt(strs[0]);
        int k = Integer.parseInt(strs[1]);
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];
        
        for(int i=0; i<n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
        
        Arrays.sort(arr);
        
        System.out.println(arr[n-k]);
    }
}