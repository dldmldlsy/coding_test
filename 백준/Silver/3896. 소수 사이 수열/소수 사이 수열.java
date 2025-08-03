import java.io.*;
import java.util.*;

public class Main 
{   
    public static int T;
    public static int K;
    public static ArrayList<Integer> prime_numbers;
    public static int result;

    public static void input(BufferedReader br) throws IOException
    {
        K = Integer.parseInt(br.readLine());
    }

    public static void solution(ArrayList<Integer> prime_numbers)
    {
        int idx = Collections.binarySearch(prime_numbers, K);
        if (idx < 0)
        {
            idx = -(idx + 1);
            result = prime_numbers.get(idx) - prime_numbers.get(idx - 1);
        }
        else
        {
            result = 0;
        }
    }

    public static void output()
    {
        System.out.println(result);
    }

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());
        int limit = 1299709;
        prime_numbers = new ArrayList<>();
        boolean[] isPrime = new boolean[limit + 1];
        for(int i = 2; i <= limit; i++)
        {
            isPrime[i] = true;
        }
        for(int i = 2; i * i <= limit; i++)
        {
            if (isPrime[i])
            {
                for(int j = i * i; j <= limit; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }
        for(int i = 2; i <= limit; i++)
        {
            if(isPrime[i])
            {
                prime_numbers.add(i);
            }
        }
        while(T > 0)
        {
            input(br);
            solution(prime_numbers);
            output();
            --T;
        }
    }
}