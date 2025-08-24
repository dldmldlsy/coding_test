import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {

    static ArrayList<ArrayList<Integer>> graph;
    
    static boolean[] visited;

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        int u, v;

        graph = new ArrayList<>();

        for(int i=0; i<=n; i++){
            graph.add(new ArrayList<>());
        }

        visited = new boolean[n+1];

        for(int i=0 ; i<m; i++){
            u = sc.nextInt();
            v = sc.nextInt();

            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        int cnt=0;
        for(int i=1; i<=n; i++){
            if(!visited[i]){
                dfs(i);
                cnt++;
            }
        }
        System.out.println(cnt);
    }

    static void dfs(int num){
        if(visited[num]){
            return;
        }
        visited[num] = true;
        for(int i=0; i<graph.get(num).size(); i++){
            if(!visited[graph.get(num).get(i)]){
                dfs(graph.get(num).get(i));
            }
        }
    }
}
