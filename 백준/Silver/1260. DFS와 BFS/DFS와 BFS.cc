#include <iostream>
#include <queue>
#include <vector> 
#include <algorithm>
using namespace std; 
vector<vector<int>> graph;
vector<int> visit; //방문: 1, 미방문: 0
void dfs(int);
void bfs(int);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, v; 
    cin>>n>>m>>v; 
    
    //정점번호가 1번부터 시작~
    //n+1 크기, 0으로 초기화
    visit.resize(n+1);
    graph.resize(n+1);
    
    for(int i=0; i<m; i++)  {
        int a, b; 
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a); 
    }
    
    //각 행돌면서 인접한 정점을 넣은 리스트에 대해 정점 번호순으로 오름차순 정렬시키기 -> 정점 낮은 순서대로 접근하기 위함.
    for(int i=1; i<=n; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    
    //dfs
    dfs(v);
    cout<<"\n";
    
    //bfs에 새로 체크해야하기 때문에 방문배열 0으로 만들기
    fill(visit.begin(), visit.end(), 0);
    
    //bfs    
    queue<int> q; 
    q.push(v);
    visit[v] = 1; 
    while(!q.empty()) {
        int cur = q.front(); 
        q.pop(); 
        //visit[cur] = 1; 
        cout<<cur<<" ";
        
        for(int i=0; i<graph[cur].size(); i++) {
            if(visit[graph[cur][i]]==0) {
                visit[graph[cur][i]] = 1; 
                q.push(graph[cur][i]);
            }
        }
    }
}

void dfs(int n) {
    if(visit[n]) {
        return; 
    }
    
    visit[n] = 1; 
    cout<<n<<" ";
    
    for(int i=0; i<graph[n].size(); i++) {
        if(!visit[graph[n][i]]) {
            dfs(graph[n][i]);
        }
    }
}