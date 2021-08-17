#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int target, int sum, int count) {
    if (count == numbers.size()) { //n개의 정수를 다 사용해서 
        if (sum == target) answer++; //타겟넘버가 되면
        return;
    }
    //더하거나 빼거나
    dfs(numbers, target, sum + numbers[count], count + 1);
    dfs(numbers, target, sum - numbers[count], count + 1);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return answer;
}