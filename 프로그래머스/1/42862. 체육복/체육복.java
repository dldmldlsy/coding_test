import java.util.*;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        
        int[] arr = new int[n+1];
        
        Arrays.sort(lost); //도난당한 학생 번호 오름차순 정렬
        
        //여벌 가져온 학생은 1 저장
        for(int i=0; i<reserve.length; i++){
            arr[reserve[i]] = 1;
        }
        
        int get=0; // 빌린 수
        int num = 0; // 도난당한 학생 번호
        for(int i=0 ;i<lost.length; i++){
            num = lost[i];
            if(arr[num]==1){ // 도난당했는데 여벌옷 가져옴 
                arr[num]=-1; // 본인이 본인한테 빌려준 경우 -1 저장
                get++; //빌린 수 증가
            }
        }
        for(int i=0; i<lost.length; i++){
            num = lost[i]; 
            if(arr[num]==-1){ //본인이 본인에게 빌려준 경우
                continue;
            }else if(num-1>=1&&arr[num-1]==1){ // 앞번호가 여벌옷 가져온 경우
                arr[num-1]=0;  //빌려줬으니까 0 으로 변경
                get++; //빌린 수 증가
            }else if(num+1<=n&&arr[num+1]==1){ //뒷번호가 여벌옷 가져온 경우
                arr[num+1]=0;
                get++;
            }
        }
        //총 학생 수 - 도난당한 학생 수 + 빌린 학생 수
        answer = n-lost.length+get;
        return answer;
    }
}