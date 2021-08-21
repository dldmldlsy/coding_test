#include <string>
#include <vector>
#include<map> //map이용(공항명 저장)
#include<algorithm> //sort이용. 
using namespace std;
struct path {//경로를 나타내는 구조체 (자료형)정의
    string s; //도착공항
    bool used = false;
};
bool cmp(path& a, path& b) {
    return a.s < b.s; //알파벳이 작은 순으로 정렬
}; 

map<string, int> m; //공항명, 번호 저장. 
vector<path> v[10001]; //v[출발공항번호]=도착공항. 
vector<string> answer; //최종 경로가 담길 벡터

path tmp; //경로를 나타내는 구조체변수 tmp선언. (전역변수)
int N; //solution에도 쓰고 dfs에서도 쓸 거라서 전역변수. 
bool finish = false;



void dfs(int idx);
vector<string> solution(vector<vector<string>> tickets) {
    
    N = tickets.size(); //티켓개수, 항공권개수

    int num = 0;

    //tickets배열 돌면서 아래 작업 반복. 
    //: (m(공항명마다 번호설정), v(출발공항번호->도착공항명=> 경로정보저장) )
    for (int i = 0; i < N; i++) { 
        string s1 = tickets[i][0]; //출발공항
        string s2 = tickets[i][1]; //도착공항
        if (m[s1] == 0) m[s1] = ++num; //번호가 안붙어있으면 공항명에 번호주고, 번호증가. 
        if (m[s2] == 0) m[s2] = ++num; 
        tmp.s = s2;  //tmp의 s에 도착공항명저장. 
        v[m[s1]].push_back(tmp); //v[m[출발공항명]]=도착공항명 => v[출발공항번호]=도착공항명
    }

    //경로정보가 저장된 v벡터를 (도착공항명의)알파벳숫자가 작은 순으로 (오름차순) 정렬.
    for (int i = 1; i <= num; i++) {
        sort(v[i].begin(), v[i].end(), cmp);
    }
    answer.push_back("ICN"); //항상 ICN공항에서 출발. 
    dfs(1); 
    return answer;
}


void dfs(int idx) {
    if (finish) return;  //finish가 true면 함수 종료
    if (idx > N) { //idx가 티켓수를 초과하면 
        finish = true;  
        return; //함수종료
    }
    string cur = answer[idx - 1]; 
    //최종루트에서의 현재공항명을 담는 변수 cur. 
    //index가 idx-1인 answer의 원소에는 공항명이 담겨있음 
    //맨처음 dfs(1)=> idx=1=> answer[1-1]=answer[0]=ICN=> cur=ICN

    int val = m[cur]; //val=m[현재 공항명]=해당 공항명의 번호

    //해당 공항명의 번호를 가진 공항을 출발공항으로 하는 항공권(v[val])을 다 돌면서 반복
    for (int i = 0; i < v[val].size(); i++) {
        if (v[val][i].used) continue; // 이미 갔으면 다음으로 !
        v[val][i].used = true; //안갔으면 used를 true로 바꿔줌. 
        string next = v[val][i].s; //도착공항
        answer.push_back(next); //도착공항명을 최종경로배열인 answer에 넣음. 
        dfs(idx + 1); //다음 번호에 대해 dfs. 
        if (finish) return;//끝났으면 dfs함수 종료. 
        answer.pop_back();//안끝났으면 잘못된 경우니까 마지막 거 빼고
        v[val][i].used = false; //마지막은 방문안했다고 다시 바꿔주고 ㅓ
        //다음 i로 ㄱ ㄱ .
    }
}