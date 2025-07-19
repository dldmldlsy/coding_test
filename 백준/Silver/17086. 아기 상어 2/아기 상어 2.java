import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int[] x = {0, 1, 0, -1, 1, -1, -1, 1};
    static int[] y = {1, 0, -1, 0, 1, -1, 1, -1};
    static int n, m;
    static boolean[] visited;
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();

        int[][] space = new int[n][m];

        for(int i=0 ;i<n;i++){
            for(int j=0; j<m; j++){
                space[i][j] = sc.nextInt();
            }
        }
        int max = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(space[i][j]==1){
                    continue;
                }
                visited = new boolean[n*m];
                max = Math.max(max, bfs(i, j, space));
            }
        }
        System.out.println(max);

    }

    static int bfs(int i, int j, int[][] space) {
        Queue<Integer> q = new LinkedList<>();
        int dis = 0;
        int start = i*m + j;
        q.add(start);
        visited[start] = true;
        boolean move = false;
        boolean find = false;
        while (!find) {
            int size = q.size();
            while (size-- > 0) {
                int cur = q.remove();
                int curRow = cur / m;
                int curCol = cur % m;
                if (space[curRow][curCol] == 1) {
                    find = true;
                    break;
                }
                for (int idx = 0; idx < 8; idx++) {
                    int nextRow = curRow + x[idx];
                    int nextCol = curCol + y[idx];
                    if(nextRow>=0&&nextRow<n&&nextCol>=0&&nextCol<m){
                        int next = nextRow * m + nextCol;
                        if (!visited[next]) {
                            q.add(next);
                            visited[next] = true;
                            move = true;
                        }
                    }
                }
            }
            if (!find&&move) {
                dis++;
            }
        }
        return dis;
    }
}
