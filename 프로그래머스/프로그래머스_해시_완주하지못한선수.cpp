//¸ÊÀÌ¿ë, 
#include <string>
#include <vector>
#include<map>
using namespace std;
//using namespace stdext;
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> run; 
    for (string p: participant) {
        run[p]++;
    }
    for (string c : completion) {
        run[c]--;
    }
    for (auto r : run) {
        if (r.second > 0) {
            answer = r.first;
            break;
        }
    }

    return answer;
}