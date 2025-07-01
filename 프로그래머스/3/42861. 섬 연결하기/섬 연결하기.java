import java.util.*;

class Solution {
    static int[] parent;

    public int solution(int n, int[][] costs) {
        int answer = 0;
        
         // 1. 간선 비용 기준 오름차순 정렬
        Arrays.sort(costs, (a, b) -> a[2] - b[2]);

        // 2. Union-Find 초기화
        parent = new int[n];
        for (int i = 0; i < n; i++) parent[i] = i;

        // 3. 간선 연결
        for (int[] edge : costs) {
            int a = edge[0];
            int b = edge[1];
            int cost = edge[2];

            // 서로 다른 집합이면 연결
            if (find(a) != find(b)) {
                union(a, b);
                answer += cost;
            }
        }

        return answer;
    }
    
    // Union-Find
    static int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    static void union(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb) parent[pa] = pb;
    }
}