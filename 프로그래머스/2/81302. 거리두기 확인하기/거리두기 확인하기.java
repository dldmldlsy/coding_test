/*
대기실 5x5 5개
맨해튼 거리 2이하로 놉, 파티션 있으면 가능, 빈테이블 있으면 불가
(a1, b1), (a2, b2) 의 맨해튼 거릴: |a1-a2|+|b1-b2|
P: 응시자자리, O: 빈테이블, X: 파티션
*/
class Solution {
    public int[] solution(String[][] places) {
        int[] answer = {};
        answer = new int [5]; 
        int cnt = 0; 
        for(int idx = 0; idx<5; idx++){
            //대기실 정보
            String[] place = places[idx]; 
            //해당 대기실 거리두기 여부
            boolean isFar = true; 
            
            cnt = 0; //응시자 수
            
            //응시자 수랑 각 위치 추출하기
            for(int i=0; i<place.length; i++){
                for(int j=0; j<place[i].length(); j++){
                    if(place[i].charAt(j)=='P'){
                      cnt++;
                    }
                }
            }
            
            //응시자 위치 배열
            int[][] arr = new int[cnt][2]; 
            cnt =0; 
            for(int i=0; i<place.length; i++){
                for(int j=0; j<place[i].length(); j++){
                    if(place[i].charAt(j)=='P'){
                        arr[cnt][0] = i;
                        arr[cnt][1] = j;
                        cnt++;
                    }
                }
            }
            
            //응시자간 거리두기여부 배열
            int[][] dis = new int[cnt][cnt]; 
            //다 0으로 초기화, 거리두기여부 확인했으면 1로 변경 -> 중복 확인 방지
        
            //응시자간 거리두기여부 확인
            for(int i=0; i<cnt; i++){
                for(int j=0; j<cnt; j++){
                    //응시자랑 상대방이 이미 거리여부를 확인했으면 패스
                    if(i==j||dis[i][j]==1) continue; 
                    //거리두기 여부 확인 표시
                    dis[i][j] = 1; 
                    dis[j][i] = 1;
                
                    //응시자 위치
                    int row = arr[i][0]; 
                    int col = arr[i][1]; 
                    //상대방 위치
                    int row2 = arr[j][0]; 
                    int col2 = arr[j][1]; 
                
                    //맨해튼거리계산
                    int mhd = Math.abs(row-row2) + Math.abs(col-col2);
                    int middleIdx = 0; 
                    
                    if(mhd>2) { //2보다 크면 거리두기 지켰으므로 패스
                     continue; 
                    }else if(mhd==1) { //1이면 안지켰으므로 
                        isFar = false; //거리두기 미준수 표시 후 반복문 탈출
                        break; 
                    }else if(mhd==2) { // 2면
                        if(row==row2){ //행이 같으면 -> 열이 다름
                            //가운데에 테이블이면 거리두기실패
                            middleIdx = (col+col2)/2;
                            if(place[row].charAt(middleIdx)=='O'){
                                isFar = false; break;
                            }
                        }else if (col==col2) {//열이 같으면 -> 행이 다름
                            //가운데에 테이블이면 거리두기 실패
                            middleIdx = (row+row2)/2;
                            if(place[middleIdx].charAt(col)=='O'){
                                isFar = false; break;
                            }
                        }else{ //행열 모두 다르면 두 곳 중 하나라도 빈테이블이면 거리두기 실패
                            if(place[row].charAt(col2)=='O'||place[row2].charAt(col)=='O') {
                                isFar = false; break;
                            }
                        }
                    }
                }
                if(!isFar){
                    break;
                }
            }
            //해당 대기실 거리두기 여부 표시
            if(!isFar){
                answer[idx] = 0; 
            }else{
                answer[idx] = 1; 
            }
        }
        
        return answer;
    }
}