import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());
        int n;
        int cnt;
        while(t-->0){
            n = Integer.parseInt(br.readLine());
            cnt = 0;

            int[] dp = new int[n+1];

            dp[1] = 1; if(n==1){System.out.println(dp[n]); continue;}
            dp[2] = 2; if(n==2){System.out.println(dp[n]); continue;}
            dp[3] = 4; if(n==3){System.out.println(dp[n]); continue;}

            if(n<4){
                System.out.println(dp[n]);
            }
            for(int i=4; i<=n; i++){
                dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
            }

            System.out.println(dp[n]);
        }

    }
}
