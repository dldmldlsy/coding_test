import java.util.Scanner;

public class Main {

    static int[] dirx = {0, -1, 0, 1};
    static int[] diry = {1, 0, -1, 0};
    static boolean[][] visited;
    static int[][] campus;
    static int n, m, cnt;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();

        campus = new int[n][m];
        visited = new boolean[n][m];

        String str;
        int dyi= -1, dyj= -1;
        for(int i=0; i<n; i++){
            str = sc.next();
            for(int j=0; j<m; j++){
                Character c = str.charAt(j);
                if (c == 'O') {
                    campus[i][j] = 0;
                }else if(c == 'P'){
                    campus[i][j] = 1;
                }else if(c == 'I'){
                    campus[i][j] = 2;
                    dyi = i;
                    dyj = j;
                }else if(c == 'X'){
                    campus[i][j] = -1;
                }
            }
        }

        cnt=0;
        dfs(dyi, dyj);
        if(cnt==0){
            System.out.println("TT");
        }else {
            System.out.println(cnt);
        }
    }

    static void dfs(int x, int y){
        if(visited[x][y]){
            return;
        }
        if(campus[x][y]==1){
            cnt++;
        }
        visited[x][y] = true;

        for(int i=0; i<4; i++){
            int nextX = x + dirx[i];
            int nextY = y + diry[i];

            if(nextX>=0&&nextX<n&&nextY>=0&&nextY<m&&!visited[nextX][nextY]){
                if(campus[nextX][nextY]==1||campus[nextX][nextY]==0){
                    dfs(nextX, nextY);
                }
            }
        }
    }
}
