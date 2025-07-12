import java.util.*;

public class Main {
    static boolean[] isPrime = new boolean[100001]; // 소수 판별 배열

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();

        sieve(); // 소수 미리 구하기

        int cnt = 0;
        for (int i = A; i <= B; i++) {
            int factors = countPrimeFactors(i); // 소인수 개수 세기
            if (isPrime[factors]) cnt++;
        }
        System.out.println(cnt);
    }

    static void sieve() {
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i < isPrime.length; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < isPrime.length; j += i)
                    isPrime[j] = false;
            }
        }
    }

    static int countPrimeFactors(int n) {
        int count = 0;
        for (int i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                count++;
                n /= i;
            }
        }
        if (n > 1) count++; // 남은 소인수
        return count;
    }
}
