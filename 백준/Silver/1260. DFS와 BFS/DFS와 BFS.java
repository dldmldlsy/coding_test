import java.util.*;

public class Main {
    static ArrayList<ArrayList<Integer>> graph;
    static boolean[] visited;

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        int v = sc.nextInt(); // 탐색 시작 정점 번호

        graph = new ArrayList<>();
        visited = new boolean[n+1];

        for(int i=0; i<=n; i++){
            graph.add(new ArrayList<>());
        }

        int a, b;
        for(int i=0; i<m; i++) {
            a = sc.nextInt();
            b = sc.nextInt();
            graph.get(a).add(b);
            graph.get(b).add(a);
        }

        //정점번호 오름차순 정렬
        for(int i=1; i<=n; i++){
            Collections.sort(graph.get(i));
        }

        dfs(v);
        System.out.println();

        visited = new boolean[n+1];
        bfs(v);

    }

    static void dfs(int v){
        if(visited[v]){
            return;
        }
        visited[v]=true;
        System.out.print(v+" ");
        for(int i=0; i<graph.get(v).size(); i++){
            if(!visited[graph.get(v).get(i)]){
                dfs(graph.get(v).get(i));
            }
        }
    }

    static void bfs(int v){
        Queue<Integer> q = new ArrayDeque<>();
        q.add(v);
        visited[v] = true;
        while(!q.isEmpty()){
            int peek = q.remove();
            System.out.print(peek+" ");
            for(int i=0; i<graph.get(peek).size(); i++){
                int now = graph.get(peek).get(i);
                if(!visited[now]){
                    q.add(now);
                    visited[now] = true;
                }
            }
        }
    }
}
