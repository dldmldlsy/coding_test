import java.io.*;
import java.util.*;

public class Main {
    static int n, m, v; 
    static int[] check; 
    static ArrayList<ArrayList<Integer>> graph;
    
    static void dfs(int v){
        if(check[v]==1){
            return; 
        }
        check[v] = 1; 
        System.out.print(v+" ");
        
        for(int i=0; i<graph.get(v).size(); i++){
            if(check[graph.get(v).get(i)]==0){
                dfs(graph.get(v).get(i));
            }
        }
        return; 
    }
    
    static void bfs(int v){
        Queue<Integer> q = new LinkedList<Integer>(); 
        q.offer(v);
        check[v] = 1; 
        int now; 
        while(!q.isEmpty()){
            now = q.peek(); 
            System.out.print(now+" "); 
            q.poll(); 
            for(int i=0 ; i<graph.get(now).size(); i++){
                if(check[graph.get(now).get(i)]==0){
                    q.offer(graph.get(now).get(i));
                    check[graph.get(now).get(i)] = 1; 
                }
            }
        }
    }
    
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt(); 
        m = sc.nextInt(); 
        v = sc.nextInt(); 
        
        graph = new ArrayList<>(); 
        check = new int[n+1]; // idx = 정점 번호가 되도록.
        for(int i=0; i<=n; i++){
            graph.add(new ArrayList<Integer>()); 
        }
        int a, b; 
        for(int i=0; i<m; i++){
            a = sc.nextInt(); 
            b = sc.nextInt(); 
            
            graph.get(a).add(b); 
            graph.get(b).add(a);
        }
        
        for(int i=1; i<=n; i++){
            Collections.sort(graph.get(i)); 
        }
        
        dfs(v);
        System.out.println();
        
        Arrays.fill(check, 0); 
        
        bfs(v);
    }
}
