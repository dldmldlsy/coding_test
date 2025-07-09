import java.util.*;

class Main {
    static int n;
    static int[] t, p;
    static int max = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        t = new int[n];
        p = new int[n];

        for (int i = 0; i < n; i++) {
            t[i] = sc.nextInt();
            p[i] = sc.nextInt();
        }

        dfs(0, 0);
        System.out.println(max);
    }

    static void dfs(int day, int total) {
        if (day >= n) {
            max = Math.max(max, total);
            return;
        }
        // 상담을 하는 경우
        if (day + t[day] <= n) {
            dfs(day + t[day], total + p[day]);
        }
        // 상담을 안 하는 경우
        dfs(day + 1, total);
    }
}
