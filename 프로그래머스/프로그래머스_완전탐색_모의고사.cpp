//����1
//����Ž��-���ǰ�� - correct!
#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) { 
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first; 
}
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int size = answers.size();  //���� �� 

    vector<int> first;  //1�� ������ �� �����ϴ� ����

    //1�������� ����� 
    for(int i=1; i<=size; i++) { //���� ����ŭ �ݺ�
        //num: 1���������� ���� �����ϴ� ����, i: ������ȣ(����)
        int num = i % 5; //1%5=1, 2%5=2, 3%5=3, 4%5=4, 5%5=0, 6%5=1,,, 1,2,3,4,5 �ݺ�
        if (num == 0) num = 5;
        first.push_back(num);
    }

    for (int i = 0; i < first.size(); i++) {
        cout << first[i] << " ";
    }
    cout << endl;

    vector<int> second; //2�� ������ �� �����ϴ� ����
    //2�������� �����(2,1,2,3,2,4,2,5,2,1,,-> Ȧ����ȣ�� 2, ¦����ȣ�� 1,3,4,5 �ݺ�.
    for (int i = 1; i <= size; i++) { 
        int k = i % 8;
        if (k%2 == 1) second.push_back(2); //Ȧ����ȣ�� �� 2
        
        else if(k%8==0||k==0){ //8�ǹ������ 5
            second.push_back(5);
        }
        else if (k % 6 == 0) { //6�� ������� 4
            second.push_back(4);
        }
        else if (k % 4 == 0) { //4�� ������� 3
            second.push_back(3);
        }
        else { //2�� ������� 1
            second.push_back(1);
        }
    }
    for (int i = 0; i < first.size(); i++) {
        cout << second[i] << " ";
    }
    cout << endl;

    vector<int> third;  //3�� ������ ����� �ۼ�
    for (int i = 1; i <=size; i++) {
        int k = i % 10;
        if (k% 10 == 0 || k % 9 == 0||k==0) { //10, 9 
            third.push_back(5);
        }
        else if (k% 8 == 0 || k% 7 == 0) //8 7
            third.push_back(4);
        else if (k % 6 == 0 || k % 5 == 0) //6 5 
            third.push_back(2);
        else if (k % 4 == 0 || k % 3 == 0) //4 3
            third.push_back(1);
        else
            third.push_back(3); //2 1
    }
    for (int i = 0; i < first.size(); i++) {
        cout << third[i] << " ";
    }
    cout << endl;

    int score_f = 0, score_s = 0, score_t = 0;
    int ans; 
    for (int i = 0; i < size; i++) {
        ans = answers[i];
        if (first[i] == ans)
            score_f++;
        if (second[i] == ans)
            score_s++;
        if (third[i] == ans)
            score_t++;
    }

    vector<pair<int, int>> v;  //����, �����ڹ�ȣ
    v.push_back(make_pair(score_f,1)); 
    v.push_back(make_pair(score_s,2));
    v.push_back(make_pair(score_t,3)); 

    
    sort(v.begin(), v.end(), cmp); //�������� �������� ���� (5,1) (0,2) (0,3)

    if (v[2].first == v[0].first){ //������ ���� ���� ������ ū ������ ���ٸ� -> �� ������ ��� ���� ��. 
        answer.push_back(1); answer.push_back(2); answer.push_back(3); //1,2,3 ���
    }
    
    else if (v[2].first == v[1].first) { //ū �θ��� ������ ���ٸ� �� ���� ��ȣ�� answer�� �ֱ�
        answer.push_back(v[2].second); answer.push_back(v[1].second);
    }
    else { //���� ���� ������ ����� �Ѹ��� ���(�ǵ޻��) -> �� �Ѹ��� ��ȣ�� answer�� �ֱ�
        answer.push_back(v[2].second);
    }
    sort(answer.begin(), answer.end()); //���� ��ȣ �������� ����
    return answer;
} 
int main() {
   vector<int> v = { 1,3,2,4,2,1,3,2,4,2,1,2,3,4,5};
   vector<int> r=solution(v); 
   for (int i = 0; i < r.size(); i++)
       cout << r[i] << " ";
}