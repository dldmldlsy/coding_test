#include <string>
#include <vector>
using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    string tmp=""; 
    bool yn = false; 
    for(int i=0; i<my_string.size(); i++){
        if(my_string[i]==' '){
            if(!yn&&!tmp.empty()){ answer.push_back(tmp); tmp = ""; yn = true; } 
        }else{
            if(yn) { yn = false; } 
            tmp += my_string[i];
        }
    }
    if(!tmp.empty()){
        answer.push_back(tmp); 
    }
    
    return answer;
}