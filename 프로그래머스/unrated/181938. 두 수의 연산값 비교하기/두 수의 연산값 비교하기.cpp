#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    string abStr = to_string(a)+to_string(b); 
    int tmp = 2*a*b; 
    answer = stoi(abStr) > tmp ? stoi(abStr): tmp;
    return answer;
}