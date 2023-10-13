#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    //인덱스에 해당하는 영단어를 저장한 vector
    vector<string> v = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    string real_s = "";
    string tmp ="";
    
    for(int i=0; i<s.size(); i++){
        if(isdigit(s[i])){ //숫자면 -> 그대로 저장
            real_s+=s[i];
        }else{  //영단어면 -> 원래 숫자 찾음 
            tmp+=s[i]; //임시 문자열에 해당 영단어 옮김
            for(int j=0; j<10; j++){ //영단어 배열 돌면서 
                if(v[j].compare(tmp) ==0){ //해당하는 영단어찾음
                    real_s+=to_string(j); //벡터의 index = 영단어숫자 
                    tmp=""; //임시 문자열 초기화
                    break; 
                }
            }
        }
    }
    //string -> int 형변환
    answer = stoi(real_s);
    return answer;
}