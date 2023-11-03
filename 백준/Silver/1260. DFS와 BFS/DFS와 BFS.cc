//백준 1260번 DFS와 BFS
/*
* 주어진 그래프의 DFS결과와 BFS 결과 출력 
* 정점 N개. 정점 번호 작은 것부터 방문. 더이상 방문할 점 없으면 종료.
* 시간 2초. N: 1~1000. M:1~1000
* O(N2) 
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std; 
vector<vector<int>> graph;
vector<bool> visited; 

void dfs(int x); 
void bfs(int x); 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, start;
	cin >> n >> m >> start;

	graph.resize(n + 1);
	visited = vector<bool>(n + 1, false);

	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(start); 

	cout << "\n"; 
	fill(visited.begin(), visited.end(), false); 
	bfs(start);
	
}
void dfs(int x) {
	if (visited[x]) {
		return;
	}
	visited[x] = true; 
	cout << x << " ";
	for (int i = 0; i < graph[x].size(); i++) {
		if(!visited[graph[x][i]]) {
			dfs(graph[x][i]);
		}
	}
}
void bfs(int x) {
	queue<int> q; 
	
	q.push(x); 
	visited[x] = true;

	while (!q.empty()) {
		int f = q.front(); 
		q.pop(); 
		cout << f << " "; 

		for (int i = 0; i < graph[f].size(); i++) {
			if (!visited[graph[f][i]]) {
				visited[graph[f][i]] = true;
				q.push(graph[f][i]); 
			}
		}
	}
	

}