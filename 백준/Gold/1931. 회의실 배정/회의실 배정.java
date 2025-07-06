import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt(); 
        
        int[][] times = new int[n][2];
        
        for(int i=0; i<n; i++){
            times[i][0]= sc.nextInt();
            times[i][1] = sc.nextInt();
        }
        
        int cnt = 0;
        
        Arrays.sort(times, (t1, t2) -> {
            if(t1[1]==t2[1]){
                return Integer.compare(t1[0], t2[0]);
            }else{
                return Integer.compare(t1[1], t2[1]);
            }
        });
        
        int curTime = times[0][1];
        
        cnt++;
        
        for(int i=1; i<n; i++){
            if(times[i][0]>=curTime){
                curTime = times[i][1];
                cnt++;
            }
        }
        
        System.out.println(cnt);
    }
}