class Solution {
    public int solution(int[] rank, boolean[] attendance) {
        int answer = 0;
        int cnt = 0; //선발된 학생 수
        int find = 1; //찾고자 하는 등수
        int[] arr = new int[3]; //선발된 학생 번호 배열
        while(cnt<3){ //3명 다 선발될 때까지 반복
            for(int i=0; i<rank.length; i++){
                if(rank[i]==find){ //가장 높은 등수 찾으면
                    if(attendance[i]){//참여 가능 여부 확인
                        arr[cnt]=i; //선발
                        cnt++; find++;
                        break;
                    }else{//참여 불가능하면
                        find++; //다음 등수 찾으러 가기
                        break;
                    }
                }
            }
        }
        
        answer = 10000*arr[0]+100*arr[1]+arr[2];
        return answer;
    }
}