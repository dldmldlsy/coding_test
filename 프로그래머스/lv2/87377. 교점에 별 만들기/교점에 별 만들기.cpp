#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    set<pair<long long, long long>> coords;

    for (int i = 0; i < line.size() - 1; i++) {
        for (int j = i + 1; j < line.size(); j++) {
            long long AD_BC = (long long)line[i][0] * line[j][1] - (long long)line[i][1] * line[j][0];
            //AD - BC = 0인 경우 두 직선은 평행 또는 일치 = 교점 x
            //x= BF-ED/AD-BC, y = EC-AF/AD-BC
            if (AD_BC != 0) {
                double x = ((double)line[i][1] * line[j][2] - (double)line[i][2] * line[j][1]) / AD_BC;
                double y = ((double)line[i][2] * line[j][0] - (double)line[i][0] * line[j][2]) / AD_BC;
                
                //정수 교점 저장
                if (x - (long long)x == 0 && y - (long long)y == 0) {
                    coords.insert({ x, y });
                }
            }
        }
    }

    //최대 최소 값 초기화
    long long min_x = 9223372036854775807;
    long long max_x = -9223372036854775808;
    long long min_y = 9223372036854775807;
    long long max_y = -9223372036854775808;

    // 교점 중 최대 최소 구하기
    for (const auto& c : coords) {
        min_x = min(c.first, min_x);
        min_y = min(c.second, min_y);
        max_x = max(c.first, max_x);
        max_y = max(c.second, max_y);
    }

    //최대최소 안에서 사각형 그리기 (우선 다 .로 저장)
    for (long long y = min_y; y <= max_y; y++) {
        string tmp = "";
        for (long long x = min_x; x <= max_x; x++) {
            tmp += ".";
        }
        answer.push_back(tmp);
    }

    //정수 교점만 * 로 저장 
    for (const auto& c : coords) {
        answer[abs(c.second - max_y)][abs(c.first - min_x)] = '*';
    }

    return answer;
}