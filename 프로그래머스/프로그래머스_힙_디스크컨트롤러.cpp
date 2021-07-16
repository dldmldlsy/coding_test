#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct cmp //우선순위큐에 작업소요시간 짧은 순으로 넣기 위한 비교함수 정의
{
    bool operator()(vector<int> a, vector<int> b)//작업 소요시간 기준
    {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<vector<int>, vector <vector<int> >, cmp > q;  //작업중인데 다른 작업이 들어올때 대기하라고 넣어두는 큐
    sort(jobs.begin(), jobs.end());//요청시간 순서대로 정렬

    int i = 0;//jobs index용
    int end_time = 0; //해당 작업이 끝나는 시간.
    int total_time = 0; //총 걸린 시간

    while (i < jobs.size() || !q.empty()) //작업개수만큼반복+큐가 비지않을때까지 반복
    {
        //만약 지금 처리중인게 끝나기 전에 도착하는 일 있으면 다 대기순위에 삽입
        if (i < jobs.size() && end_time >= jobs[i][0]) //완료시간보다 다음 요청시간이 더 작으면 그 차이를 대기해야함.
        {
            q.push(jobs[i]);  //작업시간을 큐에 넣음.  
            i++;
            continue;//1개가 아닐 수도 있다
        }

        if (!q.empty()) //큐가 비지않았으면 (대기하는 게 있으면)
        {
            //젤 소요시간 짧은게 먼저 나옴
            end_time += q.top()[1]; 
            total_time += end_time - q.top()[0]; //최종 완료시간 - 처음 요청시간
            q.pop();
        }
        else//남은 대기순위가 하나도 없다
        {
            end_time = jobs[i][0];//다음 작업 ㄱㄱ //맨처음에 여기로 와서 완료시간설정됨.
        }

    }
    answer = total_time / jobs.size();
    return answer;
}