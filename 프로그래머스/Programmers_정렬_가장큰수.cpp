//정답!
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;//최종 h-index
    vector<int> v; //h-index후보 
    int h = 0;
    for (int i = 0; i < citations.size(); i++) {
        if (h < citations[i]) h = citations[i];
    }
    for (int i = 0; i <=h; i++) { 
        int count = 0;
        for (int j = 0; j < citations.size(); j++) {
            if (citations[j] >= i)
                count++;
        }
        if (count >= i)
            v.push_back(i);
    }
    for (int i = 0; i < v.size(); i++) {
        if (answer < v[i]) answer = v[i];
    }

    return answer;
}