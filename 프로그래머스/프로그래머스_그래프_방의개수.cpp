//그래프_레벨5
// 문제가 재밌음. 어려움. 구글링 ㅇㅇ.
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> arrows) {
    int answer = 0;

    vector<int> dx = { 0, 1, 1, 1, 0, -1, -1, -1 };
    vector<int> dy = { 1, 1, 0, -1, -1, -1, 0, 1 };

    map<pair<int, int>, bool> visitedNode;
    map<pair<pair<int, int>, pair<int, int>>, bool> visitedEdge;

    int curX = 0;
    int curY = 0;
    visitedNode[make_pair(0, 0)] = true;

    for (int i = 0; i < arrows.size(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int nextX = curX + dx[arrows[i]];
            int nextY = curY + dy[arrows[i]];

            if (visitedNode[make_pair(nextX, nextY)] == true && visitedEdge[make_pair(make_pair(curX, curY), make_pair(nextX, nextY))] == false)
                answer++;

            visitedNode[make_pair(nextX, nextY)] = true;
            visitedEdge[make_pair(make_pair(curX, curY), make_pair(nextX, nextY))] = true;
            visitedEdge[make_pair(make_pair(nextX, nextY), make_pair(curX, curY))] = true;

            curX = nextX;
            curY = nextY;
        }
    }
    return answer;
}