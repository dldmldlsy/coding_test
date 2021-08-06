#include <string>
#include <vector>
 
using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.length();  
    string s(len, 'A'); // �־��� ���ڿ����̸�ŭ A�� ������ ���ڿ�
    // a b c d e f g h i j   k l m n o p q r s t   u v w x y z  26 (65~90)
 
    int i = 0;
    while (1) {
        s[i] = name[i]; 
        if (name[i] - 'A' > 'Z' + 1 - name[i])
            answer += 'Z' + 1 - name[i];
        else
            answer += name[i] - 'A';
        if (s == name) break; 

        //���� ���� ���� 
        for (int j = 1; j < len; j++) {
            //���������� �̵�
            if (name[(i + j) % len] != s[(i + j) % len]){
                i=(i+j)%len; 
                answer+=j; 
                break; 
                }
            //�������� �̵�
            else if (name[(i + len - j) % len] != s[(i + len - j) % len]) {
                i = (i + len - j) % len; 
                answer += j; 
                break; 
            }

        }
    }
        return answer; 
}