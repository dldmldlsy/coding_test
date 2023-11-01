#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    string tmp = "";
    for(auto ms : my_string){
        if(ms==' '){
            answer.push_back(tmp);
            tmp="";

        }else{
            tmp += ms;
        }
    }
    answer.push_back(tmp);
    return answer;
}