#include <string>
#include <vector>
#include<algorithm>
using namespace std;
bool cmp(vector<int> a, vector<int>b) { return a[2] < b[2]; } //비용기준 오름차순정렬

int parent[100]; 
int find(int a) { //최상위 부모섬을 찾을 때까지 재귀 
    if (a == parent[a]) return a;
    else return find(parent[a]);
}
void union_(int a, int b) {
    //두 섬의 최상위부모섬 찾기
    a = find(a);
    b = find(b);
    
    //최상위부모섬 기록. (더 작은 숫자로 )
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    sort(costs.begin(), costs.end(), cmp);

    for (int i = 0; i < n; i++) parent[i] = i;
    for (int i = 0; i < costs.size(); i++) { //다리 연결작업. 
        int a = costs[i][0]
            ;
        int b = costs[i][1]; 
        int cost = costs[i][2]; 
        
        //최상위 부모섬이 서로 같으면 이때 이으면 사이클이 만들어짐 => ekfmf ruddndp
        if (find(a) != find(b))// 다리 설치
        {union_(a, b); //합치기
        answer += cost; 
        }
    }
    return answer;
}