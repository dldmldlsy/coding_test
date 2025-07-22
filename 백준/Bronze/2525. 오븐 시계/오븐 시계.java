import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();

        int totalM = a*60 + b+ c;
        int hour = totalM/60;
        hour = hour%24;
        int minutes = totalM%60;

        System.out.println(hour + " " + minutes);
    }
}
