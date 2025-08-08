import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        // 빠른 입력을 위해 BufferedReader 사용
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 테스트 케이스 개수
        int t = Integer.parseInt(br.readLine());
        int n, m; // A 배열 크기, B 배열 크기

        // 테스트 케이스 반복
        while(t-- > 0){
            // N과 M 입력
            String[] str = br.readLine().split(" ");
            n = Integer.parseInt(str[0]); // A 배열 크기
            m = Integer.parseInt(str[1]); // B 배열 크기

            // A와 B 배열 선언
            int[] arr = new int[n];
            int[] brr = new int[m];

            // A 배열 원소 입력
            String[] aStr = br.readLine().split(" ");
            for(int i = 0; i < n; i++){
                arr[i] = Integer.parseInt(aStr[i]);
            }

            // B 배열 원소 입력
            String[] bStr = br.readLine().split(" ");
            for(int i = 0; i < m; i++){
                brr[i] = Integer.parseInt(bStr[i]);
            }

            // B 배열을 오름차순 정렬
            Arrays.sort(brr);
            int cnt=0;

            for(int i=0; i<n; i++){
                cnt+= lowerBound(brr, arr[i]);
            }

            // 결과 출력
            System.out.println(cnt);
        }
    }

    public static int lowerBound(int[] array, int target){
        int left = 0;
        int right = array.length;

        while(left<right){
            int mid = (left+right)/2;
            if(array[mid]<target){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return left;
    }
}