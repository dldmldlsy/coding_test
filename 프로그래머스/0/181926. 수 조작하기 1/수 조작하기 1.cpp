#include <string>
#include <vector>

using namespace std;

int solution(int n, string control) {
    int answer = 0;
    for(char c : control) {
        if(c == 'w'){
            n++;
        } else if (c=='s') {
            n--;
        } else if (c=='d') {
            n+=10;
        } else if (c=='a') {
            n-=10;
        }
    }
    answer = n;
    return answer;
}