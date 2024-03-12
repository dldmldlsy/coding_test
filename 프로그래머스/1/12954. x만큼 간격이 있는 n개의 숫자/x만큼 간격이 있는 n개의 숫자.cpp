#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    long long a = 0; 
    while(n--) {
        a += x; 
        answer.push_back(a);
    }
    return answer;
}