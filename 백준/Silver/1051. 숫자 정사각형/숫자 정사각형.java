import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc= new Scanner(System.in);
        
        int n = sc.nextInt();
        int m = sc.nextInt(); 
        
        int[][] squares = new int[n][m];
        for(int i=0; i<n; i++){
            String str = sc.next(); 
            for(int j=0; j<m; j++){
                squares[i][j] = str.charAt(j)-'0';
            }
        }
        
        int size = Math.min(n, m);
        
        int first = 0; 
        int second = 0; 
        int third = 0; 
        int four = 0; 
        for(int i=size; i>0; i--){
            
            for(int r=0; r<n; r++){
                for(int c=0; c<m; c++){
                    if(c+i-1>=m||r+i-1>=n){
                        continue;
                    }
                    first = squares[r][c];
                    second = squares[r][c+i-1];
                    third = squares[r+i-1][c];
                    four = squares[r+i-1][c+i-1];
                    if(first==second&&second==third&&third==four){
                        System.out.println(i*i);
                        return;
                    }
                }
            }          
            
        }
        
       
    }
}