#include <string>
#include <vector>

using namespace std;
int answer = 51; //words의 최대 size가 50.

bool isChangable(string str1, string str2) { //변환가능여부판단 
    int diff = 0; 
    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] != str2[i]) { //두 문자열이 다르면
            diff++; //diff증가
        }
    }
    if (diff == 1) return true; //한개만 다르면 변환가능
    else return false; //두개이상이면 불가능. 
}

void dfs(string begin, string target, vector<string> words, vector<bool>& visited, int count) {
    for (int i = 0; i < words.size(); i++) { //단어배열을 돌면서 작업 반복
        if (isChangable(begin, words[i])) { // 변환 가능하면 
            // 최종 도착 여부 검사 -> 종료
            if (target == words[i]) { //최종타깃이랑 같으면 
                if (count + 1 < answer) { //100보다 작으면 
                    answer = count + 1; //횟수로 바꿔주고
                    return;//종료
                }
            }

            // 방문 여부 검사 -> 다시 탐색
            if (visited[i] == false) {//방문한 적 없으면
                visited[i] = true; //방문했다표시
                dfs(words[i], target, words, visited, count + 1);
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    vector<bool> visited(words.size(), false); 

    dfs(begin, target, words, visited, 0);

   if (answer == 50) return 0;
   else
    return answer;
}