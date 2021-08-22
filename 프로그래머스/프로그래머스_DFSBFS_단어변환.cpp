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

void dfs(string begin, string target, vector<string> words, vector<bool>& visited, int count) {
    for (int i = 0; i < words.size(); i++) { //�ܾ�迭�� ���鼭 �۾� �ݺ�
        if (isChangable(begin, words[i])) { // ��ȯ �����ϸ� 
            // ���� ���� ���� �˻� -> ����
            if (target == words[i]) { //����Ÿ���̶� ������ 
                if (count + 1 < answer) { //100���� ������ 
                    answer = count + 1; //Ƚ���� �ٲ��ְ�
                    return;//����
                }
            }

            // �湮 ���� �˻� -> �ٽ� Ž��
            if (visited[i] == false) {//�湮�� �� ������
                visited[i] = true; //�湮�ߴ�ǥ��
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