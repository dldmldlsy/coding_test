#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    //알파벳 총 개수: 26
    
    for(int i=0; i<s.size(); i++){
        if(s[i]>='A'&&s[i]<='Z'){ //대문자
            if(s[i]+n>'Z'){ //밀었을 때 Z를 넘기면 
                s[i]+= n-'Z'-1+'A';
            }else{
                s[i]+= n; 
            }
        }else if(s[i]>='a'&&s[i]<='z'){ //소문자
            if(s[i]+n>'z'){ //밀었을 때 z를 넘기면
                s[i]+= n-'z'-1+'a';
            }else{
                s[i]+=n;
            }
        }
    }
    answer=s;
    return answer;
}