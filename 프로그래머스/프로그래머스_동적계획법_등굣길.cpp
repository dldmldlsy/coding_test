#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    int answers[m][n];

    vector<pair<int, int> > puddle;

    for (int i = 0; i < puddles.size(); i++)
    {
        puddle.push_back(make_pair(puddles[i][0] - 1, puddles[i][1] - 1)); //위치를 인덱스로 알 수 있게 저장
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                answers[i][j] = 1;
            }
            else if (find(puddle.begin(), puddle.end(), make_pair(i, j)) != puddle.end()) // 잠긴 지역의 위치라면
            {
                answers[i][j] = 0; 
            }
            else if (i == 0) //잠긴지역의 위치가 아니고 0행이면 오른쪽으로 가면 
            {
                answers[i][j] = answers[i][j - 1] % 1000000007;
            }
            else if (j == 0) // 아래로 감
            {
                answers[i][j] = answers[i - 1][j] % 1000000007;
            }
            else
            {
                answers[i][j] = (answers[i - 1][j] + answers[i][j - 1]) % 1000000007;
            }

        }
    }
    answer = answers[m - 1][n - 1];
    return answer;
}