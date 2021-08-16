#include <string>
#include <vector>
using namespace std;

//�������� �μ��� �� ū���� ����. 
int solution(vector<vector<int>> triangle) {
    int answer = 0;

    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (j != 0 && j < triangle[i - 1].size())//�糡�� �ƴ� ���
                triangle[i][j] += max(triangle[i - 1][j], triangle[i - 1][j - 1]); //�밢����,���߿� ū ��
            else if (j == 0) //���ʳ�
                triangle[i][j] += triangle[i - 1][j];
            else//�����ʳ�
                triangle[i][j] += triangle[i - 1][j - 1];

            answer = max(answer, triangle[i][j]);
        }
    }
    return answer;
}