import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        int[] arr = new int[n];

        String[] strs = br.readLine().split(" ");
        for(int i=0; i<n; i++){
            arr[i] = Integer.parseInt(strs[i]);
        }

        int x = Integer.parseInt(br.readLine());

        Arrays.sort(arr);

        int left = 0;
        int right = n-1;
        int cnt = 0;
        int sum;
        while(left<right) {
            sum = arr[left]+arr[right];
            if(sum==x){
                cnt++;
                left++;
            }else if(sum<x){
                left++;
            }else if(sum>x){
                right--;
            }
        }

        System.out.println(cnt);
    }
}
