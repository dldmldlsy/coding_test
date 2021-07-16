#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct cmp //�켱����ť�� �۾��ҿ�ð� ª�� ������ �ֱ� ���� ���Լ� ����
{
    bool operator()(vector<int> a, vector<int> b)//�۾� �ҿ�ð� ����
    {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<vector<int>, vector <vector<int> >, cmp > q;  //�۾����ε� �ٸ� �۾��� ���ö� ����϶�� �־�δ� ť
    sort(jobs.begin(), jobs.end());//��û�ð� ������� ����

    int i = 0;//jobs index��
    int end_time = 0; //�ش� �۾��� ������ �ð�.
    int total_time = 0; //�� �ɸ� �ð�

    while (i < jobs.size() || !q.empty()) //�۾�������ŭ�ݺ�+ť�� �������������� �ݺ�
    {
        //���� ���� ó�����ΰ� ������ ���� �����ϴ� �� ������ �� �������� ����
        if (i < jobs.size() && end_time >= jobs[i][0]) //�Ϸ�ð����� ���� ��û�ð��� �� ������ �� ���̸� ����ؾ���.
        {
            q.push(jobs[i]);  //�۾��ð��� ť�� ����.  
            i++;
            continue;//1���� �ƴ� ���� �ִ�
        }

        if (!q.empty()) //ť�� �����ʾ����� (����ϴ� �� ������)
        {
            //�� �ҿ�ð� ª���� ���� ����
            end_time += q.top()[1]; 
            total_time += end_time - q.top()[0]; //���� �Ϸ�ð� - ó�� ��û�ð�
            q.pop();
        }
        else//���� �������� �ϳ��� ����
        {
            end_time = jobs[i][0];//���� �۾� ���� //��ó���� ����� �ͼ� �Ϸ�ð�������.
        }

    }
    answer = total_time / jobs.size();
    return answer;
}