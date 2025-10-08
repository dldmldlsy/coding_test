import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int k = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());

        int[] lines = new int[k];

        for(int i=0; i<k; i++){
            lines[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(lines);

        long left = 1;
        long right = lines[k-1];
        long mid, sum;
        long answer = 0;
        while(left<=right){
            mid = left+(right-left)/2;
            sum = 0;
            for(int i=0; i<k; i++){
                sum += lines[i]/mid;
            }
            if(sum>=n){
                answer = mid;
                left = mid+1;
            }else{//sum<n
                right = mid-1;
            }
        }

        System.out.println(answer);
    }
}
