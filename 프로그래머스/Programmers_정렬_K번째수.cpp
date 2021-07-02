//Á¤´ä
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int i, j, k;
    for (int p = 0; p < commands.size(); p++) {
        i = commands[p][0];
        j = commands[p][1];
        k = commands[p][2];
        vector<int> v;
        for (int m = i; m < j + 1; m++) {
            v.push_back(array[m - 1]);
        }
        int s = v.size(); int x;
        for (int a = 0; a < s - 1; a++) {
            for (int b = a + 1; b < s; b++) {
                if (v[a] > v[b]) {
                    x = v[a];
                    v[a] = v[b];
                    v[b] = x;
                }
            }
        }
        answer.push_back(v[k - 1]);
    }

    return answer;
}