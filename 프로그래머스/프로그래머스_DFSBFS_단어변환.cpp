#include <string>
#include <vector>
#include<queue>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int wordsN = words.size();  
    int beginN = begin.size(); 
    vector<int> visit(wordsN, 0); //ũ�Ⱑ �ܾ���̰� �� ���Ҹ� 0���� �ʱ�ȭ�� ����
    queue<pair<string, int>> q; // ť(���۴ܾ�, ��ȯ�ܰ�)
    q.push({ begin, 0 }); // ��ó�� ���۴ܾ�, 0 ����. 

    int j, d; 
    while (!q.empty()) {
        string start = q.front().first; // ť�� ��� �� ��  ������ ���۴ܾ�. 
        int count = q.front().second; // ť�� ��� �� �տ����� ��ȯ�ܰ�. 
        q.pop(); //�Ǿ� �� ����. 
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