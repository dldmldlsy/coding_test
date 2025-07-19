import java.util.*;

class Solution {
    ArrayList<ArrayList<Integer>> network;
    boolean[] visited;
    public int solution(int n, int[][] computers) {
        int answer = 0;
        network = new ArrayList<>();
        for(int i=0 ;i<n; i++){
            network.add(new ArrayList<>());
        }
        visited = new boolean[n];
        for(int i=0; i<computers.length; i++){
            for(int j=0; j<computers[0].length; j++){
                if(i==j){continue;}
                if(computers[i][j]==1){
                    network.get(i).add(j);
                }
            }
        }
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i);
                answer++;
                System.out.println(i);
            }
        }
        return answer;
    }
    
    void dfs(int cn){
        if(visited[cn]){
            return;
        }
        visited[cn]=true;
        for(int i=0; i<network.get(cn).size(); i++){
            if(!visited[network.get(cn).get(i)]){
                dfs(network.get(cn).get(i));
            }
        }
    }
}