import java.util.*; 
class Solution {
    boolean[][] visited;
    int n, m;
    int[] dirX = {0, -1, 0, 1};
    int[] dirY = {1, 0, -1, 0};
    public int solution(int[][] maps) {
        int answer = 0;
        n = maps.length;
        m = maps[0].length;
        visited = new boolean[n][m];
        answer = bfs(0, 0, maps);
        return answer;
    }
    int bfs(int x, int y, int[][] maps){
        Queue<Integer> q = new LinkedList<>();
        int pass = 1;
        q.add(x*m+y);
        visited[x][y] = true;
        boolean move = false;
        boolean arrive = false;
        while(!arrive){
            int size = q.size();
            move = false;
            while(size-->0){
                int cur = q.remove();
                int curX = cur/m; 
                int curY = cur%m;
                if(curX == n-1&& curY == m-1){
                    arrive = true; 
                    break;
                }
                for(int i=0; i<4; i++){
                    int nextX = curX + dirX[i];
                    int nextY = curY + dirY[i];
                    if(nextX>=0&&nextX<n&&nextY>=0&&nextY<m){
                        if(!visited[nextX][nextY]&&maps[nextX][nextY]==1){
                            q.add(nextX*m + nextY);
                            visited[nextX][nextY] =true;
                            move = true;
                        }
                    }
                }
            }
            if(arrive){ break; }
            if(q.isEmpty()){
                pass = -1;
                break;
            }
            pass++;
        }
        return pass;
    }
}