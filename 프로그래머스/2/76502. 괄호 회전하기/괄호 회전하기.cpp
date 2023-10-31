#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

unordered_map <char, char> m = {{'{', '}'}, {'[', ']'}, {'(', ')'}};

int is_right(string str)
{//올바른 괄호문자열인지
    stack <char> st;

    for(int i=0;i<str.size();i++)
    {
        if (m[str[i]]) st.push(str[i]);// '[' '{' '(' 이면
        else if (!st.empty() && m[st.top()] == str[i]) st.pop();// 그외 스택이 비어있지않고 괄호 짝이 맞다면
        else st.push(str[i]);// 그외
    }
    if (!st.empty()) return (0);
    return (1);
}

int solution(string s)
{
    int answer = 0, len = s.size();
    for(int i=0;i<len;i++)
    {
        string tmp = s.substr(i, len-i) + s.substr(0, i);// 왼쪽으로 i만큼 회전시킨 새로운 문자열
        answer += is_right(tmp);
    }
    return answer;
}