import java.util.*;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        
        // arr[학생번호] = 체육복 소유 여부 (0: 미소유, 1: 소유)
        int[] arr = new int[n+1];
        
        //전체 학생 체육복 소유했다고 설정
        Arrays.fill(arr, 1);
        
        //도난당한 학생들만 0값 부여
        for(int i=0; i<lost.length; i++){
            arr[lost[i]]=0; 
        }
        //처음 체육복 소유자 수: 전체학생 수 - 도난 당한 학생 수
        answer = n-lost.length;
        
        //여벌옷 학생들 오름차순 정렬
        Arrays.sort(reserve);
        
        //여벌 옷 학생들이 빌려줄 수 있는지 조회 (학생 번호 범위 체크/ 앞뒤 도난여부 체크)
        for(int i=0; i<reserve.length; i++){
            if(arr[reserve[i]]==0){ //본인이 도난당한 경우
                arr[reserve[i]]=3; answer++; 
            }
        }
        
        for(int i=0; i<reserve.length; i++){
            if(arr[reserve[i]]==3){ //본인이 도난당한 경우
                continue;
            }else if((reserve[i]-1)>0 && arr[reserve[i]-1]==0){//앞사람이 도난당한 경우
                arr[reserve[i]-1]=1; answer++;
            }else if(reserve[i]+1<(n+1)&& arr[reserve[i]+1]==0){//뒷사람이 도난당한 경우
                arr[reserve[i]+1]=1; answer++;
            }
        }

        return answer;
    }
}