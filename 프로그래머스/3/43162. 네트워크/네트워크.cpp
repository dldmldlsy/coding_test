#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> graph;
vector<bool> visit;
int cnt =0; 
void dfs(int);
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    visit.resize(n, false); 
    graph = computers; 

    for(int i=0 ;i<n;i++) {
        cnt =0; 
        dfs(i);
        if(cnt>0) {
            answer++; 
        }
    }

    return answer;
}

void dfs(int n) {
    if(visit[n]) {
        return; 
    }
    
    visit[n]=true;
    cnt++; 
    
    for(int i=0; i<graph[n].size(); i++) {
        if(graph[n][i]==1&& visit[i]==false)  {
            dfs(i);
        }
    }
}