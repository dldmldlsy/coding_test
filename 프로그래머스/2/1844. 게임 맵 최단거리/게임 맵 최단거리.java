import java.util.*;

class Solution {
    public int solution(int[][] maps) {
        int n = maps.length;
        int m = maps[0].length;

        // 방문 여부 및 거리 기록 겸용
        int[][] visited = new int[n][m];

        // 방향 벡터: 상하좌우
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};

        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{0, 0});
        visited[0][0] = 1; // 시작 위치 거리 1

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int x = current[0];
            int y = current[1];

            // 상하좌우 탐색
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                // 맵 범위 벗어나면 무시
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

                // 이동 가능한 칸이고 아직 방문 안한 곳만
                if (maps[nx][ny] == 1 && visited[nx][ny] == 0) {
                    visited[nx][ny] = visited[x][y] + 1;
                    queue.offer(new int[]{nx, ny});
                }
            }
        }

        // 도착 못 했으면 -1
        if (visited[n - 1][m - 1] == 0) {
            return -1;
        }

        // 도착 위치의 거리 반환
        return visited[n - 1][m - 1];
    }
}
