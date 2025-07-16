import java.util.Scanner;

public class Main {

    static int[] dirX = {-1, 0, 1, 0, -1, -1, 1, 1};
    static int[] dirY = {0, 1, 0, -1, -1, 1, -1, 1};
    static int[][] map;
    static int w, h;
    static boolean[][] visited;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        while(true){
            w = sc.nextInt();
            h = sc.nextInt();
            if(w==0&&h==0){
                break;
            }
            map = new int[h][w];
            visited = new boolean[h][w];

            for(int i=0; i<h; i++){
                for(int j=0; j<w; j++){
                    map[i][j] = sc.nextInt();
                }
            }
            int cnt = 0;
            for(int i=0; i<h; i++){
                for(int j=0; j<w; j++){
                    if(!visited[i][j]&&map[i][j]==1){
                        dfs(i, j);
                        cnt++;
                    }
                }
            }

            System.out.println(cnt);

        }

    }

    static void dfs(int c, int r){
        if(visited[c][r]){
            return;
        }

        visited[c][r] = true;

        for(int i=0; i<8; i++){
            int nextC = c + dirX[i];
            int nextR = r + dirY[i];
            if(nextC<h&&nextC>=0&& nextR<w&& nextR>=0){
                if(!visited[nextC][nextR]&&map[nextC][nextR]==1){
                    dfs(nextC, nextR);
                }
            }
        }
    }
}
