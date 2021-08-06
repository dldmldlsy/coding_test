#include <string>
#include <vector>
#include<algorithm>
#include<deque>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end()); 

    deque<int> d; 
    for (int i = 0; i < people.size(); i++) {
        d.push_back(people[i]);
    }
    while (!d.empty()) {
        if (d.size() > 1 && d.back() + d.front() <= limit) {
            d.pop_front(); d.pop_back();
        }
        else
            d.pop_back(); 
        answer++;
    }
    return answer;
}