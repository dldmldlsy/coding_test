#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    vector<vector<int>> snail(n, vector<int>(n, 0)); //nxn 0으로 초기화
    int i=0, j=0, num=1; 
    
    while(1){
        bool end = true; 
        while(i+1<n && snail[i+1][j]==0){
            //아래로 갈 수 있을 때까지 내려가기 (하향)
            snail[i++][j] = num++;
            end = false; 
        }
        if(end) break; 
        while(j+1<n && snail[i][j+1]==0){
            snail[i][j++]=num++;
            end=false; 
        }
        if(end) break; 
        while(i-1>0 && j-1>0&&snail[i-1][j-1]==0){
            snail[i--][j--]=num++;
            end=false;
        }
        if(end) break;
    }
    snail[i][j]=num; 
    
    for(auto s: snail){
        for(auto si: s){
            if(si) answer.push_back(si);
        }
    }
    return answer;
}