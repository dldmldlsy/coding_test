#include <string>
#include <vector>
#include<queue>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int wordsN = words.size();  
    int beginN = begin.size(); 
    vector<int> visit(wordsN, 0); //크기가 단어수이고 각 원소를 0으로 초기화한 벡터
    queue<pair<string, int>> q; // 큐(시작단어, 변환단계)
    q.push({ begin, 0 }); // 맨처음 시작단어, 0 삽입. 

    int j, d; 
    while (!q.empty()) {
        string start = q.front().first; // 큐에 담긴 맨 앞  원소의 시작단어. 
        int count = q.front().second; // 큐에 담긴 맨 앞원소의 변환단계. 
        q.pop(); //맨앞 거 삭제. 
        for (int i = 0; i < wordsN; i++) {
            d = 0;
            if (visit[i] != 0) continue; 
            for (int j = 0; i < beginN; j++) {
                if (start[j] != words[i][j])
                    d++;
            }
            if (d == 1) {
                if (words[i] == target) {
                    return count + 1; 
                }
                visit[i] = 1;
                q.push({ words[i],count + 1 });
            }
        }
    }
    return answer;
}