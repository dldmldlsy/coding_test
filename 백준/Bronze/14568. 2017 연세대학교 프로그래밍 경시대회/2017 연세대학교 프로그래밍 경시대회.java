import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int cnt = 0;
        int a, b, c;
        for(int i=1; i<=n-2; i++){
            a = i;
            for(int j=1; j<=n-1-i; j++){
                b = j;
                c = n-(i+j);
                if(a+b+c!=n){
                    continue;
                }
                if(a>=b+2&&c%2==0){
                    cnt++;
                }
            }
        }

        System.out.println(cnt);
    }
}