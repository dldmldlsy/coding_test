//Ʋ�� 
//sort�Լ����� cmp�Լ����� �����ϸ� ��� 
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    for (int i = 0; i < numbers.size() - 1; i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            string a = to_string(numbers[i]);
            string b = to_string(numbers[j]);
            if (a + b < b + a) {
                int x = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = x;
            }
        }
    }
    if (answer[0] == '0')  return"0";
    for (int i = 0; i < numbers.size(); i++)
        answer += to_string(numbers[i]);
    return answer;
}