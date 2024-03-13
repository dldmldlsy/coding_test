//달리기 경주
//- 바로 앞의 선수 추월 시, 추월한 선수 이름 호명
//- 경주 끝났을 때, 등수 오름차순
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> answer;
    map<string, int> m; // m[이름] = 등수
    map<int, string> m2; //m2[등수] = 이름
    int rank = 1; 
    //이름 -> 등수, 등수-> 이름 찾을 수 있도록 각 map에 저장
    for(string s: players) {
        m[s] = rank;
        m2[rank] = s;
        rank++;
    }
    
    // 해설진 호명에 따라서 등수 변경 
    for(string s: callings) {
        int pass_rank = m[s]; //추월한 사람 기존 등수
        string back_name = m2[pass_rank-1]; //추월 당한 사람의 이름 
        //등수 바꿈
        m[s] = pass_rank-1; 
        m[back_name] = pass_rank;
        m2[pass_rank-1] = s;
        m2[pass_rank] = back_name;
    }
    
    // 선언만 된 벡터에 일정 크기에 특정 값을 할당
    answer.assign(players.size(), "");
    // 각 등수-1이 벡터의 index가 되도록 
    for(auto iter = m.begin(); iter!=m.end(); iter++) {
        answer[(*iter).second-1]=(*iter).first;
    }
        
    return answer;
}