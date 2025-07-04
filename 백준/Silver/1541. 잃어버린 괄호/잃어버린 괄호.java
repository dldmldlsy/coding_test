import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();

        String[] sub = str.split("-");

        int result = sum(sub[0]);  // 첫 덩어리는 더함
        for (int i = 1; i < sub.length; i++) {
            result -= sum(sub[i]);  // 나머지는 다 더해서 빼기
        }

        System.out.println(result);
    }

    static int sum(String s) {
        int sum = 0;
        String[] arr = s.split("\\+");
        for (String a : arr) {
            sum += Integer.parseInt(a);
        }
        return sum;
    }
}
