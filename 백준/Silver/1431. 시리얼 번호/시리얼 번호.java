import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        String[] serial = new String[n];

        for(int i=0; i<n; i++){
            serial[i] = sc.next();
        }

        Arrays.sort(serial, (s1, s2)->{
           if(s1.length()!=s2.length()){
               return s1.length() - s2.length();
           }else{
               int sum1 = 0;
               int sum2 = 0;
               for(int i=0; i<s1.length(); i++){
                   if(Character.isDigit(s1.charAt(i))){
                       sum1+= s1.charAt(i)-'0';
                   }
                   if(Character.isDigit(s2.charAt(i))){
                       sum2+= s2.charAt(i)-'0';
                   }
               }
               if(sum1!=sum2){
                   return sum1-sum2;
               }
           }
           return s1.compareTo(s2);
        });


        for(int i=0; i<n; i++){
            System.out.println(serial[i]);
        }
    }
}
