import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int o = 0;
        int x = 0;
        List<Integer> olist = new ArrayList<>();
        List<Integer> xlist = new ArrayList<>();
        while(true){
            String str = sc.nextLine();
            o=0;
            x=0;
            olist.clear(); xlist.clear();
            if(str.equals("end")){
                break;
            }
            for(int i=0; i<9; i++){
                if(str.charAt(i)=='O'){
                    o++;
                    olist.add(i);
                }else if(str.charAt(i)=='X') {
                    x++;
                    xlist.add(i);
                }
            }
            if((o<3&&x<3)|| o>x){
                System.out.println("invalid");
                continue;
            }
            int cnt = 0;
            int oWin = 0;
            int xWin = 0;
            if(olist.contains(0)&&olist.contains(1)&&olist.contains(2)){
                cnt++; oWin++;
            }
            if(olist.contains(3)&&olist.contains(4)&&olist.contains(5)){
                cnt++; oWin++;
            }
            if(olist.contains(6)&&olist.contains(7)&&olist.contains(8)) {
                cnt++; oWin++;
            }
            if(olist.contains(0)&&olist.contains(3)&&olist.contains(6)){
                cnt++; oWin++;
            }
            if(olist.contains(1)&&olist.contains(4)&&olist.contains(7)){
                cnt++; oWin++;
            }
            if(olist.contains(2)&&olist.contains(5)&&olist.contains(8)){
                cnt++; oWin++;
            }
            if(olist.contains(0)&&olist.contains(4)&&olist.contains(8)){
                cnt++; oWin++;
            }
            if(olist.contains(2)&&olist.contains(4)&&olist.contains(6)){
                cnt++; oWin++;
            }
            if(xlist.contains(0)&&xlist.contains(1)&&xlist.contains(2)){
                cnt++; xWin++;
            }
            if(xlist.contains(3)&&xlist.contains(4)&&xlist.contains(5)){
                cnt++; xWin++;
            }
            if(xlist.contains(6)&&xlist.contains(7)&&xlist.contains(8)) {
                cnt++; xWin++;
            }
            if(xlist.contains(0)&&xlist.contains(3)&&xlist.contains(6)){
                cnt++; xWin++;
            }
            if(xlist.contains(1)&&xlist.contains(4)&&xlist.contains(7)){
                cnt++; xWin++;
            }
            if(xlist.contains(2)&&xlist.contains(5)&&xlist.contains(8)){
                cnt++; xWin++;
            }
            if(xlist.contains(0)&&xlist.contains(4)&&xlist.contains(8)){
                cnt++; xWin++;
            }
            if(xlist.contains(2)&&xlist.contains(4)&&xlist.contains(6)){
                cnt++; xWin++;
            }
            if(x==5&&o==4&&xWin==0&&oWin==0){
                System.out.println("valid");
                continue;
            }else if((oWin==1||oWin==2)&&x!=o) {
                System.out.println("invalid");
                continue;
            }else if((xWin==1||xWin==2)&&x!=o+1){
                System.out.println("invalid");
                continue;
            }else if(cnt==1||cnt==2){
                System.out.println("valid");
                continue;
            }else{
                System.out.println("invalid");
            }


        }
    }
}