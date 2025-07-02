import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        String str = sc.nextLine();
        int zero = 0 ;
        int one = 0;
        int idx = 0;
        while(idx<str.length()){
            char c = str.charAt(idx);
            if(c=='0'){
                zero++;
            }else{
                one++;
            }
            while(idx<str.length()&&str.charAt(idx)==c){
                idx++;
            }
        }
        
        System.out.println(Math.min(zero, one));
    }
}