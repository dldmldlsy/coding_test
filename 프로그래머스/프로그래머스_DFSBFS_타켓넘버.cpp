#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int target, int sum, int count) {
    if (count == numbers.size()) { //n���� ������ �� ����ؼ� 
        if (sum == target) answer++; //Ÿ�ٳѹ��� �Ǹ�
        return;
    }
    //���ϰų� ���ų�
    dfs(numbers, target, sum + numbers[count], count + 1);
    dfs(numbers, target, sum - numbers[count], count + 1);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return answer;
}