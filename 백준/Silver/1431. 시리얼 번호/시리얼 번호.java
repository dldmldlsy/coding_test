import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str = br.readLine();
        int n = Integer.parseInt(str);

        String[] numbers = new String[n];
        for(int i=0; i<n; i++){
            numbers[i] = br.readLine();
        }

        Arrays.sort(numbers, (g1, g2) -> {
          if(g1.length() != g2.length()){
              return g1.length()-g2.length();
          }else{
              //길이가 같으면 -> 숫자합
              int sum1 = 0;
              int sum2 = 0;
              for(int i=0; i<g1.length(); i++){
                  if(Character.isDigit(g1.charAt(i))) {
                      sum1 += g1.charAt(i)-'0';
                  }
                  if(Character.isDigit(g2.charAt(i))) {
                      sum2 += g2.charAt(i)-'0';
                  }
              }
              if(sum1 != sum2){
                  return sum1-sum2;
              }else{
                  //숫자합도 같다면 -> 사전순
                  return g1.compareTo(g2);
              }
          }
        });

        StringBuilder sb = new StringBuilder();
        for(String number : numbers){
            sb.append(number+"\n");
        }
        System.out.println(sb);
    }
}



