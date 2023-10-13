#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    //길이 체크: 길이가 4도 아니고 6도 아닌 경우 -> false
    if(s.size()!=4 && s.size()!=6){
        answer = false;
    }
    //원소 구성 체크: 숫자로만 구성되어있는지 확인
    for(auto ss: s){
        if(!isdigit(ss)){
            answer=false; 
            break;
        }
    }
    return answer;
}