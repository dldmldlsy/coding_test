import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt(); // 스위치 개수
        
        int[] buttons = new int[n]; 
        
        for(int i=0; i<n; i++){
            buttons[i] = sc.nextInt();
        }
        
        int cnt = sc.nextInt(); //학생수
        
        int[][] condition = new int[cnt][2];
        
        for(int i=0; i<cnt; i++){
            condition[i][0] = sc.nextInt(); //학생 성별
            condition[i][1] = sc.nextInt(); //학생 받은 수
        }
        
        int getNumber = 0; //받은 수
        
        
        for(int i=0; i<cnt; i++){
            if(condition[i][0]==1){ //남학생
                getNumber = condition[i][1]; 
                int num = n/getNumber; //스위치수/받은수 = 배수 개수
                while(num>0){ 
                    //받은수*배수 개수= 스위치번호인 스위치 상태변경 
                    // 스위치번호-1 = 해당 스위치 idx
                    buttons[num*getNumber-1] = buttons[num*getNumber-1]==0? 1 : 0;
                    num--;
                }
            }else if(condition[i][0]==2){ //여학생
                getNumber = condition[i][1];
                int start=getNumber-1; //중심 스위치 idx
                int end = getNumber-1; //중심 스위치 idx
                while(start>=0&&end<n){
                    if(start-1>=0&&end+1<n&&buttons[start-1]==buttons[end+1]){
                        start=start-1;
                        end=end+1;
                    }else{
                        break;
                    }
                }
                
                for(int j=start; j<=end; j++){
                    buttons[j] = buttons[j]==0 ? 1: 0;
                }                
            }
        }
        
        System.out.print(buttons[0]);
        for(int i=1; i<n; i++){
            if(i%20==0){
                System.out.println();
            }else{
                System.out.print(" ");
            }
            System.out.print(buttons[i]);
        }
    }
    
}