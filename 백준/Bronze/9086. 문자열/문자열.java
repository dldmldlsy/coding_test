import java.io.*;

class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int t = Integer.parseInt(br.readLine());
        String answer = "";
        while(t-->0){
            answer = "";
            String str = br.readLine();
            answer += str.charAt(0);
            answer += str.charAt(str.length()-1);
            System.out.println(answer);
        }
        
    }
}