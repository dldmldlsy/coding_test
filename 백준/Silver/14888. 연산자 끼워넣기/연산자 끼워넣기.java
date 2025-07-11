import java.util.Scanner;

public class Main {
    static int[] ops = new int[4];
    static int[] numbers;
    static int cnt;
    static int n;
    static int result;
    static int max = Integer.MIN_VALUE;
    static int min = Integer.MAX_VALUE;

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        numbers = new int[n];

        for(int i=0 ;i<n; i++){
            numbers[i] = sc.nextInt();
        }

        for(int i=0; i<4; i++){
            ops[i] = sc.nextInt();
        }
        cnt =0;
        result = 0;

            dfs(cnt, numbers[0], 1);


        System.out.println(max);
        System.out.println(min);

    }

    static void dfs(int cnt, int result, int numberIdx){
        if(cnt==(n-1)){
            if(min>result){
                min = result;
            }
            if(max<result){
                max = result;
            }
            return;
        }
        int nextResult = 0;
        for(int i=0 ;i<4; i++){
            if(ops[i]==0){
                continue;
            }else if(i==0){ //plus
                nextResult = result + numbers[numberIdx];
            }else if(i==1){ //minus
                nextResult = result - numbers[numberIdx];

            }else if(i==2){ //multi
                 nextResult = result * numbers[numberIdx];

            }else if(i==3){ //div
                nextResult = result / numbers[numberIdx];
            }
            ops[i] -= 1;
            dfs(cnt+1, nextResult, numberIdx+1);
            ops[i] += 1;
        }
    }
}
