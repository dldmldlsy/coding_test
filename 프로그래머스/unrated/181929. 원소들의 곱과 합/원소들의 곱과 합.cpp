#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int mult = 1; int sum = 0;  
    for(auto num: num_list){
        mult*=num;
        sum+=num; 
    }
    answer = mult>pow(sum, 2) ? 0: 1; 
    return answer;
}