import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        // Scanner 대신 BufferedReader/Writer 사용 (빠른 입출력)
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int[] count = new int[10001]; // 숫자 범위가 1~10000

        for (int i = 0; i < n; i++) {
            int num = Integer.parseInt(br.readLine());
            count[num]++; // 등장 횟수 증가
        }

        for (int i = 1; i <= 10000; i++) {
            while (count[i] > 0) {
                bw.write(i + "\n"); // 해당 숫자 출력
                count[i]--;
            }
        }

        bw.flush();
        bw.close();
        br.close();
    }
}
