#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int index = 0;
    for(auto c: s){
        if(c==' '){
            index=-1;
        }
        if(index%2==0 && islower(c)){
            answer+=toupper(c);
        }else if(index%2==1 && isupper(c)){
            answer+=tolower(c);
        }else{
            answer+=c;
        }
        index++;
    }
    return answer;
}