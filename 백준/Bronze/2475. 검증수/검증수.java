import java.io.*;

class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String[] strs = br.readLine().split(" ");
        int answer = 0;
        for(int i=0; i<strs.length; i++){
            answer += Math.pow(Integer.parseInt(strs[i]), 2);
        }
        
        answer %= 10;
        
        System.out.println(answer);
        
    }
}