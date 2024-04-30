#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int w = 0;
    int h = 0;
    for(vector<int> size: sizes) {
        w = max(max(size[0], size[1]), w);
        h = max(min(size[0], size[1]), h);
    }
    answer = w*h;
    return answer;
}