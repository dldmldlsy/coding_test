#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> visit(1000001,false); // 방문표시 + 해당 값에 도달하는 최소 연산수 
int solution(int x, int y, int n) {
    int answer = 0;
    
    queue<int> q; 
    q.push(x); //x넣기
        
    while(!q.empty()){
        int now = q.front(); 
        q.pop();
        //x=y면 그때의 now의 연산횟수 반환
        if(now == y) return visit[now];
        //가능한 연산 
        int oper[3] = {now+n, now*2, now*3};
        
        for(int i=0; i<3; i++){
            int nx = oper[i];//연산적용한 값  
            if(nx>y || visit[nx]!=0){
                continue; //범위밖이거나 방문했었으면 pass
            }
            visit[nx] = visit[now]+1; //해당 값이 될 때까지의 최소 연산수 
            q.push(nx); 
        }
    }
    
    //모든 경우의 수를 돌 때까지 return되지 않았다는 것은 y로 만들 수 없다는 뜻  
    return -1;
}