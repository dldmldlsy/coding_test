//���͵�-������ȹ��

//������ȹ��? ��ü ������ ���� ������ �ܼ�ȭ�� ��, ��ȭ���� ���� ����� ������ Ȱ���� �ذ�. 

//�޸������̼�(Memoization):  �Լ����� ����ϰ� ���� ���� �迭�� ���� (�ʿ��� ������ �Լ� ��ȣ�⺸�� ������ �� ������ �� ����) 


#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

int get_NNN(int N, int cnt) {
    int res = 0;

    while (cnt > 0) {
        cnt -= 1;//1--=0 
        res += N * pow(10, cnt); //10^0, 10^1, 10^2,,,=> 5, 55, 555, 5555, ,,,
    }

    return res;
}

int solution(int N, int number) {
    if (N == number) { //N�� number�� �����ϸ� 1����
        return 1;
    }

    int answer = -1; //�켱 -1�� �ʱ�ȭ. 

    //1. [ {} x 8 ] �ʱ�ȭ
    auto s = vector<set<int>>(8); //�������迭����. ���;ȿ� ��. 
    // 2. �� set���� �⺻ �� "N" * i �� �ʱ�ȭ
    int idx = 1;

    for (auto& x : s) { //1�࿡ 5, 2�࿡ 55, 3�࿡ 555,,,�ֱ�
        x.insert(get_NNN(N, idx)); //(5,1) (5,2) (5, 3) (5,4) (5,5)...
        idx += 1;
    }

    //3. n �Ϲ�ȭ
    //   { 
    //       "n" * i, 
    //       1�� set ��Ģ���� n-1�� set, 
    //       2�� set ��Ģ���� n-2�� set, 
    //       ...
    //       n-1�� set ��Ģ���� 1�� set, 
    //    } 
    // number�� ���� �ּҷ� ����� �� ����.
    for (int i = 1; i < 8; i++) {
        for (int j = 0; j < i; j++) {
            for (const auto& pre : s[j]) {
                for (const auto& cur : s[i - j - 1]) {
                    s[i].insert(pre + cur);
                    s[i].insert(pre - cur); 
                    s[i].insert(pre * cur);

                    if (cur != 0)
                        s[i].insert(pre / cur);
                }
            }
        }

        if (s[i].find(number) != s[i].end()) { //�� �࿡ number�� ������ 
            answer = i + 1; //�� �࿡ N�� ���Ե� ������ �ε���+1�̹Ƿ� i+1. 
            break;
        }
    }

    return answer;
}

int main() {
    int N = 5;
    int number = 12;
    auto result = solution(N, number);
    cout << result << endl;
    return 0;
}