#include <string>
#include <vector>

using namespace std;
bool check[201]; 
void dfs(vector<vector<int>> v, int idx) {
    for (int i = 0; i < v[idx].size(); i++) {
        if (v[idx][i] == 1 && check[i] == false) {
            check[i] = true; 
            dfs(v, i);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
     
    for (int i = 0; i < n; i++) {
        if (check[i] == false) {
            dfs(computers, i);
            answer++;
        }
    }
    return answer;
}

