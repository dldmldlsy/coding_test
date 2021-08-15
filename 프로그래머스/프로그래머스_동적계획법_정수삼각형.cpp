#include <string>
#include <vector>
using namespace std;

//내려갈때 두수중 더 큰수를 택함. 1
int solution(vector<vector<int>> triangle) {
    int answer = 0;

    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (j != 0 && j < triangle[i - 1].size())
                triangle[i][j] += max(triangle[i - 1][j], triangle[i - 1][j - 1]);
            else if (j == 0)
                triangle[i][j] += triangle[i - 1][j];
            else
                triangle[i][j] += triangle[i - 1][j - 1];

            answer = max(answer, triangle[i][j]);
        }
    }
    return answer;
}