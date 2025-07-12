import java.util.*;

public class Main {
    static int N;
    static int[] nums;
    static int[] ops = new int[4]; // + - * /
    static int max = Integer.MIN_VALUE;
    static int min = Integer.MAX_VALUE;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        nums = new int[N];
        for (int i = 0; i < N; i++) nums[i] = sc.nextInt();
        for (int i = 0; i < 4; i++) ops[i] = sc.nextInt();

        dfs(1, nums[0]);
        System.out.println(max);
        System.out.println(min);
    }

    static void dfs(int idx, int result) {
        if (idx == N) {
            max = Math.max(max, result);
            min = Math.min(min, result);
            return;
        }

        for (int i = 0; i < 4; i++) {
            if (ops[i] > 0) {
                ops[i]--;

                int next = 0;
                if (i == 0) next = result + nums[idx];
                else if (i == 1) next = result - nums[idx];
                else if (i == 2) next = result * nums[idx];
                else if (i == 3) next = result / nums[idx];

                dfs(idx + 1, next);
                ops[i]++;
            }
        }
    }
}
