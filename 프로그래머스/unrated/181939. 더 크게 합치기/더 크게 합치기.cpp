#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    string abStr = to_string(a)+to_string(b); 
    string baStr = to_string(b)+to_string(a); 
    int ab = stoi(abStr); 
    int ba = stoi(baStr); 
    answer = ab > ba ? ab: ba; 
    return answer;
}