//레벨1
//완전탐색-모의고사 - correct!
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
    int size = answers.size();  //문제 수 

    vector<int> first;  //1번 수포자 답 저장하는 벡터

    //1번수포자 답안지 
    for(int i=1; i<=size; i++) { //문제 수만큼 반복
        //num: 1번수포자의 답을 저장하는 변수, i: 문제번호(개수)
        int num = i % 5; //1%5=1, 2%5=2, 3%5=3, 4%5=4, 5%5=0, 6%5=1,,, 1,2,3,4,5 반복
        if (num == 0) num = 5;
        first.push_back(num);
    }

    for (int i = 0; i < first.size(); i++) {
        cout << first[i] << " ";
    }
    cout << endl;

    vector<int> second; //2번 수포자 답 저장하는 벡터
    //2번수포자 답안지(2,1,2,3,2,4,2,5,2,1,,-> 홀수번호는 2, 짝수번호는 1,3,4,5 반복.
    for (int i = 1; i <= size; i++) { 
        int k = i % 8;
        if (k%2 == 1) second.push_back(2); //홀수번호는 다 2
        
        else if(k%8==0||k==0){ //8의배수에는 5
            second.push_back(5);
        }
        else if (k % 6 == 0) { //6의 배수에는 4
            second.push_back(4);
        }
        else if (k % 4 == 0) { //4의 배수에는 3
            second.push_back(3);
        }
        else { //2의 배수에는 1
            second.push_back(1);
        }
    }
    for (int i = 0; i < first.size(); i++) {
        cout << second[i] << " ";
    }
    cout << endl;

    vector<int> third;  //3번 수포자 답안지 작성
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

    vector<pair<int, int>> v;  //점수, 수포자번호
    v.push_back(make_pair(score_f,1)); 
    v.push_back(make_pair(score_s,2));
    v.push_back(make_pair(score_t,3)); 

    
    sort(v.begin(), v.end(), cmp); //점수기준 오름차순 정렬 (5,1) (0,2) (0,3)

    if (v[2].first == v[0].first){ //세명중 제일 작은 점수와 큰 점수가 같다면 -> 세 점수가 모두 같은 것. 
        answer.push_back(1); answer.push_back(2); answer.push_back(3); //1,2,3 출력
    }
    
    else if (v[2].first == v[1].first) { //큰 두명의 점수가 같다면 두 명의 번호를 answer에 넣기
        answer.push_back(v[2].second); answer.push_back(v[1].second);
    }
    else { //가장 높은 점수의 사람이 한명일 경우(맨뒷사람) -> 이 한명의 번호를 answer에 넣기
        answer.push_back(v[2].second);
    }
    sort(answer.begin(), answer.end()); //들어온 번호 오름차순 정렬
    return answer;
} 
int main() {
   vector<int> v = { 1,3,2,4,2,1,3,2,4,2,1,2,3,4,5};
   vector<int> r=solution(v); 
   for (int i = 0; i < r.size(); i++)
       cout << r[i] << " ";
}