import java.util.*;


public class Main {
    static boolean[] visited = new boolean[100000+1];
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();
        bfs(n, k);
    }
    static void bfs(int start, int goal){
        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        visited[start] = true;
        int time = 0;
        boolean find = false;
        while(!find){
            ArrayList<Integer> list = new ArrayList<>();
            while(!q.isEmpty()){
                list.add(q.remove());
            }
            for(int num: list){
                if(num==goal){
                    find = true;
                    break;
                }else {
                    int[] nexts = {num-1, num+1, num*2};
                    for(int next : nexts){
                        if(next>=0&&next<=100000&&!visited[next]){
                            q.add(next);
                            visited[next] = true;
                        }
                    }
                }
            }
            if(!find){
                time++;
            }
        }
        System.out.println(time);
    }
}
