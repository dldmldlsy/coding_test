import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());

        while(t-->0){
            int n = Integer.parseInt(br.readLine());

            StringTokenizer st = new StringTokenizer(br.readLine());
            int[] arr = new int[n];
            for(int i=0; i<n; i++){
                arr[i] = Integer.parseInt(st.nextToken());
            }

            Arrays.sort(arr);

            int max = 0;
            ArrayList<Integer> list = new ArrayList<>();

            for(int i=0; i<n; i++){
                if(i%2==0){
                    list.add(arr[i]);
                }
            }

            for(int i=n-1; i>=0; i--){
                if(i%2==1){
                    list.add(arr[i]);
                }
            }
            int level = 0;
            for(int i=0; i<list.size(); i++){
                if(i==list.size()-1){
                    level = Math.abs(list.get(list.size()-1)-list.get(i));
                }else{
                    level = Math.abs(list.get(i)-list.get(i+1));
                }
                if(max < level){
                    max = level;
                }
            }
            System.out.println(max);
        }

    }
}
