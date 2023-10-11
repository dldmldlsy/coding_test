#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    
    int answer = s.size(); //기존 문자열 길이로 초기화
    
    int cnt; string tmp="", a="";
    
    for(int i=1; i<=s.size()/2; i++){
        cnt=1; 
        tmp="", a=""; 
        a=s.substr(0, i); //0~i까지 자른 문자열 a
        for(int j=i; j<s.size(); j+=i){//i+1부터 길이가 i인 문자열
            if(a==s.substr(j, i)) cnt++; //a와 같다면 반복횟수 ++ 
            else{//같지않다면 이전까지반복된정보로 압축하여 저장
                //2이상 반복시 반복횟수 문자열에 함께 저장
                if(cnt>1) tmp+= to_string(cnt); 
                tmp+=a; 
                //반복이후(같지않았던) i길이의 문자열로 a 변경
                a=s.substr(j,i); 
                cnt=1; //cnt도 1로 변경
            }
        }
        if(cnt>1){
            tmp+=to_string(cnt); 
        }
        tmp+=a;
        //answer보다 길이가 작은 경우-> 압축된 문자열 길이 반환
        if(answer>tmp.size()) answer=tmp.size(); 
    }
    return answer;
}