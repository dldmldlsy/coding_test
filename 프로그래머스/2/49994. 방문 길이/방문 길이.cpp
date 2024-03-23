#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
//동서남북 
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, -0, -1, 1};

int solution(string dirs) {
    int answer = 0;
    //간선 방문 배열
    bool visit[11][11][4]; 
    memset(visit, false, sizeof(visit));
    
    int x = 5; 
    int y = 5; 
    
    for(int i=0; i<dirs.size(); i++) {
        int dir = 0; int count_dir = 0; 
        char cmd = dirs[i]; 
        
        //명령어에 따른 방향 설정
        if(cmd == 'R') {
            dir = 0; 
            count_dir = 1; 
        } else if (cmd=='L') {
            dir = 1; 
            count_dir = 0; 
        } else if (cmd == 'D'){
            dir = 2; 
            count_dir = 3; 
        }else { //U
            dir = 3; 
            count_dir = 2; 
        }
        
        //다음 좌표
        int nx = x + dx[dir]; 
        int ny = y + dy[dir];
        
        //좌표 경계 범위 체크 : 범위 초과 시 해당 명령어 무시
        if(nx <0 || ny <0 || nx >= 11 || ny >= 11) continue; 
        
        //간선 기록 및 방문 길 개수 카운트
        if(!visit[x][y][dir]&&!visit[nx][ny][count_dir]) {
            visit[x][y][dir] = true; 
            visit[nx][ny][count_dir] = true; 
            answer++;
        }
        
        x= nx; 
        y = ny; 
        
    }
    
    return answer;
}