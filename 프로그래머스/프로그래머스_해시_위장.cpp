#include <string>
#include <vector>
#include<map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map<string, int> c;
    for (int i = 0; i < clothes.size(); i++) {
        string name = clothes[i][1];
        if (c.find(name) != c.end()) {
            c[name]++;
        }
        else
            c[name] = 1; //c.insert({name,1});
    } int sum = 1;
    for (map<string, int>::iterator iter = c.begin(); iter !=c.end();iter++){
            sum *= iter->second+1;
    } 
        answer = sum - 1;
       return answer;
}
