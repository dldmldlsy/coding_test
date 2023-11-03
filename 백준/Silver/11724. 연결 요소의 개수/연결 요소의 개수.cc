//백준 11724번 연결 요소의 개수
/*
* 무방향 그래프 -> 연결요소 개수 구하라. 
* 시간 3초. 정점 n은 1000개 이하 간선 m  
* 노드 최대 수 1000, O(n2)이하 알고리즘 모두 가능. 
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

vector<vector<int>> graph;	
vector<bool> visited;
void dfs(int x);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); 

	int n, m; 
	cin >> n >> m; 
	int u, v;
	graph.resize(n + 1);
	//방문배열 
	visited = vector<bool>(n + 1, false); 

	for (int i = 0; i <m; i++) {
		cin >> u>> v; 
		graph[u].push_back(v); 
		graph[v].push_back(u); 
	}

	int cnt = 0; //연결요소 개수 
	
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			cnt++; 
			dfs(i); 
		}
	}
	cout << cnt << "\n"; 
}
void dfs(int x) {
	if (visited[x]) {
		return; 
	}
	visited[x] = true; 
	for (int vertex : graph[x]) {
		if (visited[vertex] == false) {
			dfs(vertex); 
		}
	}
}