#include<string>
#include <iostream>
#include<stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st; //스택 st
    
    // 닫는 괄호로 시작한다면 
    if(s[0]==')'){
        answer =false; //false 리턴
        return answer;
    }else{ //여는 괄호로 시작한다면
        st.push(s[0]); //스택에 여는 괄호 저장
    }
    //문자열 돌면서 괄호쌍 확인
    for(int i=1; i<s.length(); i++){
        //여는 괄호가 나오면 스택에 저장
        if(s[i] == '('){
            st.push(s[i]);
        }else{ 
            //닫는 괄호가 나올 시, 스택이 비어있는지 확인 
            //-> 비어있다면 닫는 괄호가 짝인 여는 괄호가 없다는 뜻 => false
            if(st.empty()){answer = false; break;}
            //닫는 괄호가 나오면 스택에 있는 여는 괄호 하나를 pop. -> 짝 지음 
            st.pop();
        }
    }
    //스택이 비어있으면 올바른 괄호
    //스택이 비어있지 않으면 올바르지 않은 괄호
    if(!st.empty()){
        answer=false;
    }
    
    return answer;
}