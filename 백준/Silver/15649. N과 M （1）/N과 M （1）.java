import java.util.Scanner;

public class Main {
    static int n, m;
    static boolean[] visited;  // 숫자 사용 여부 체크
    static int[] arr;          // 현재 수열 저장

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();

        visited = new boolean[n + 1];
        arr = new int[m];

        dfs(0);
    }

    static void dfs(int depth) {
        if (depth == m) { // m개를 고르면 출력
            for (int i = 0; i < m; i++) {
                System.out.print(arr[i] + " ");
            }
            System.out.println();
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {   // 아직 안 쓴 숫자면
                visited[i] = true;
                arr[depth] = i;  // 현재 깊이에 숫자 저장
                dfs(depth + 1);  // 다음 자리로 이동
                visited[i] = false; // 백트래킹 (원상 복구)
            }
        }
    }
}
