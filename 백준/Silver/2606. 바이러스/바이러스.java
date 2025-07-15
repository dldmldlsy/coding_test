import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static ArrayList<ArrayList<Integer>> graph;
    static boolean[] visited;
    static int cnt;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int computers = sc.nextInt();
        int networks = sc.nextInt();

        visited = new boolean[computers+1];
        graph = new ArrayList<>();
        cnt=0;

        for(int i=0; i<=computers; i++){
            graph.add(new ArrayList<>());
        }

        //컴퓨터-네트워크 연결
        for(int i=0; i<networks; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            graph.get(a).add(b);
            graph.get(b).add(a);
        }
        dfs(1);
        System.out.println(cnt-1);

    }

    static void dfs(int n){
        if(visited[n]){
            return;
        }
        visited[n] = true;
        cnt++;
        for(int i=0; i<graph.get(n).size(); i++){
            if(!visited[graph.get(n).get(i)]){
                dfs(graph.get(n).get(i));
            }
            //visited[graph.get(n).get(i)] = false;
        }
    }
}
