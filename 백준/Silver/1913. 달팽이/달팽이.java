import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int target = sc.nextInt();

        int[][] arr = new int[N][N];

        // 방향: 상, 우, 하, 좌
        int[] dx = {-1, 0, 1, 0};
        int[] dy = {0, 1, 0, -1};

        int x = N / 2;
        int y = N / 2;
        arr[x][y] = 1;

        int num = 2;
        int length = 1;
        int targetX = x;
        int targetY = y;

        while (num <= N * N) {
            for (int dir = 0; dir < 4; dir++) {
                for (int i = 0; i < length; i++) {
                    x += dx[dir];
                    y += dy[dir];

                    if (x >= 0 && x < N && y >= 0 && y < N) {
                        arr[x][y] = num;
                        if (num == target) {
                            targetX = x;
                            targetY = y;
                        }
                        num++;
                    }
                }
                if (dir == 1 || dir == 3) { // 우, 좌 방향 끝나면 길이 +1
                    length++;
                }
            }
        }

        // 출력
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println((targetX + 1) + " " + (targetY + 1));  // 1-based 좌표
    }
}
