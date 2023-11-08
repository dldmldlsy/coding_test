//프로그래머스 0단계 문자열 겹쳐쓰기
#include <string>
#include <vector>

using namespace std;
//인덱스 s부터 overwrite 길이만큼을 overwrite으로 바꾼 문자열 반환
string solution(string my_string, string overwrite_string, int s) {
    string answer = "";
    for(int i=0; i<overwrite_string.size(); i++){
        my_string[s+i]=overwrite_string[i];
    }
    answer= my_string; 
    return answer;
}