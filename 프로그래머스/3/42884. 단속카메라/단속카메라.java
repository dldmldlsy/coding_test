import java.util.*;

class Solution {
    public int solution(int[][] routes) {
        int answer = 0;
        
        Arrays.sort(routes, (r1, r2)->(r1[1]-r2[1]));
        ArrayList<Integer> cameras = new ArrayList<Integer>();
        cameras.add(routes[0][1]);
        boolean pass = false; 
        for(int i=1;i <routes.length; i++){
            pass=false;
            for(int c : cameras){
                if(routes[i][0]<=c&&routes[i][1]>=c){
                    pass = true;
                    break;
                }
            }
            if(!pass){
                cameras.add(routes[i][1]);
            }
        }
        return cameras.size();
    }
}