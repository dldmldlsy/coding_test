#include <string>
#include <vector>
#include<algorithm>
using namespace std;
bool cmp(vector<int> a, vector<int>b) { return a[2] < b[2]; } //������ ������������

int parent[100]; 
int find(int a) { //�ֻ��� �θ��� ã�� ������ ��� 
    if (a == parent[a]) return a;
    else return find(parent[a]);
}
void union_(int a, int b) {
    //�� ���� �ֻ����θ� ã��
    a = find(a);
    b = find(b);
    
    //�ֻ����θ� ���. (�� ���� ���ڷ� )
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    sort(costs.begin(), costs.end(), cmp);

    for (int i = 0; i < n; i++) parent[i] = i;
    for (int i = 0; i < costs.size(); i++) { //�ٸ� �����۾�. 
        int a = costs[i][0]
            ;
        int b = costs[i][1]; 
        int cost = costs[i][2]; 
        
        //�ֻ��� �θ��� ���� ������ �̶� ������ ����Ŭ�� ������� => ekfmf ruddndp
        if (find(a) != find(b))// �ٸ� ��ġ
        {union_(a, b); //��ġ��
        answer += cost; 
        }
    }
    return answer;
}