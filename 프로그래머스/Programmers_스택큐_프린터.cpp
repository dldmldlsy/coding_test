//correct!
#include <string>
#include <vector>
#include<queue>
using namespace std;
int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> q;
    vector<int> v;
    for (int i = 0; i < priorities.size(); i++) {
        q.push(priorities[i]);
        v.push_back(priorities[i]);
    }
    int i = 1;
    int count = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        bool printer = true;
        for (int j = i; j < v.size(); j++)
        {
            if (now < v[j]) {
                q.push(now);
                v.push_back(now);
                printer = false;
                if (i-1 == location) location = v.size() - 1;
                break;
            }
        }
        if (printer)
        {
           // cout << now << " "; 
            count++;
            if (i-1 == location) {
                answer = count;
            }
        }
            i++;
    }
    return answer;
}