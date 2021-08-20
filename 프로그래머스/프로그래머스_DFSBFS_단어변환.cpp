//#include <string>
//#include <vector>
//#include<queue>
//using namespace std;
//
//int solution(string begin, string target, vector<string> words) {
//    int answer = 0;
//    int wordsN = words.size();  
//    int beginN = begin.size(); 
//    vector<int> visit(wordsN, 0); //ũ�Ⱑ �ܾ���̰� �� ���Ҹ� 0���� �ʱ�ȭ�� ����
//    queue<pair<string, int>> q; // ť(���۴ܾ�, ��ȯ�ܰ�)
//    q.push({ begin, 0 }); // ��ó�� ���۴ܾ�, 0 ����. 
//
//    int j, d; 
//    while (!q.empty()) {
//        string start = q.front().first; // ť�� ��� �� ��  ������ ���۴ܾ�. 
//        int count = q.front().second; // ť�� ��� �� �տ����� ��ȯ�ܰ�. 
//        q.pop(); //�Ǿ� �� ����. 
//        for (int i = 0; i < wordsN; i++) {
//            d = 0;
//            if (visit[i] != 0) continue; 
//            for (int j = 0; i < beginN; j++) {
//                if (start[j] != words[i][j])
//                    d++;
//            }
//            if (d == 1) {
//                if (words[i] == target) {
//                    return count + 1; 
//                }
//                visit[i] = 1;
//                q.push({ words[i],count + 1 });
//            }
//        }
//    }
//    return answer;
//}


#include <string>
#include <vector>

using namespace std;
int answer = 51; //words�� �ִ� size�� 50.

bool isChangable(string str1, string str2) { //��ȯ���ɿ����Ǵ� 
    int diff = 0; 
    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] != str2[i]) { //�� ���ڿ��� �ٸ���
            diff++; //diff����
        }
    }
    if (diff == 1) return true; //�Ѱ��� �ٸ��� ��ȯ����
    else return false; //�ΰ��̻��̸� �Ұ���. 
}

void dfs(string begin, string target, vector<string> words, vector<bool>& visited, int time) {
    for (int i = 0; i < words.size(); i++) { //�ܾ�迭�� ���鼭 �۾� �ݺ�
        if (isChangable(begin, words[i])) { // ��ȯ �����ϸ� 
            // ���� ���� ���� �˻� -> ����
            if (target == words[i]) { //����Ÿ���̶� ������ 
                if (time + 1 < answer) { //100���� ������ 
                    answer = time + 1; //Ƚ���� �ٲ��ְ�
                    return;//����
                }
            }

            // �湮 ���� �˻� -> �ٽ� Ž��
            if (visited[i] == false) {//�湮�� �� ������
                visited[i] = true; //�湮�ߴ�ǥ��
                dfs(words[i], target, words, visited, time + 1);
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    vector<bool> visited(words.size(), false); 

    dfs(begin, target, words, visited, 0);

   if (answer == 51) return 0;//?
   else
    return answer;
}