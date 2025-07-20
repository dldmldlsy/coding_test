import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    static boolean[] visited;
    static int n;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();

        int[][] graph = new int[n][n];

        for(int i=0; i<n; i++){
            String str = sc.next();
            for(int j=0; j<n;j++){
                if(str.charAt(j)=='N'){
                    graph[i][j] = 0;
                }else{
                    graph[i][j] = 1;
                }
            }
        }

        int max = 0;
        for(int i=0; i<n; i++){
            visited = new boolean[n];
            max = Math.max(max, bfs(i, graph));
        }

        System.out.println(max);
    }
    static int bfs(int num, int[][] graph){
        Queue<Integer> q = new LinkedList<>();
        int cnt = 0;
        q.add(num);
        int friends = 0;
        int cur = q.remove();
        for(int i=0; i<n; i++){
            if(cur==i) {continue;}
            if(graph[cur][i]==1&&!visited[i]){
                q.add(i);
                visited[i] = true;
                cnt++;
            }
        }
        while(cnt-->0){
            cur = q.remove();
            for(int i=0; i<n; i++){
                if(num==i) {continue;}
                if(graph[cur][i]==1&&!visited[i]){
                    visited[i] = true;
                }
            }
        }
        for(int i=0; i<n; i++){
            if(visited[i]){
                friends++;
            }
        }
        return friends;
    }
}
