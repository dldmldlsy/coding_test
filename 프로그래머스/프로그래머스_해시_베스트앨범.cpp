#include <string>
#include <vector>
#include<map>
#include<algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<pair<int, pair<int, string>>> v; //재생횟수, 고유번호, 장르 저장. 
    for (int i = 0; i < genres.size(); i++) {
        v.push_back(make_pair(plays[i], make_pair(i, genres[i]))); // 횟수, (고유번호, 장르) 
    }
    // 재생횟수를 내림차순정렬( 장르 내에서 많이 재생된 노래 먼저) 
    sort(v.begin(), v.end()); 
    reverse(v.begin(), v.end()); 
   
    //속한 노래가 많이 재생된 장르 ->  장르벡터에서 중복 원소가 없도록제거. 
    sort(genres.begin(), genres.end()); 
    genres.erase(unique(genres.begin(), genres.end()), genres.end()); 
    //unique() 

    vector<pair<int, string>> genres_sum; //장르합(재생수, 장르) 

    //장르별 재생횟수 합치기
    for (string g : genres) { //중복원소없는 장르벡터 하나씩 돌면서(=각 장르)
        int sum = 0;
        for (int i = 0; i < v.size(); i++) { //각 노래돌면서 해당장르 재생횟수 합치기
            if (g == v[i].second.second) { //해당장르가 이 벡터의 두번째(페어) 두번째원소(=장르)와 같다면 
                sum+=v[i].first; //재생횟수 더하기 
            }
        }
        genres_sum.push_back(make_pair(sum, g)); //장르별재생수합, 장르 저장

    }

    //장르별 재생수 많이 재생된 순으로 정렬 (내림차순)
    sort(genres_sum.begin(), genres_sum.end());
    reverse(genres_sum.begin(), genres_sum.end());

    //각 장르별 재생많이될수록, 고유번호 낮을 수록 먼저 수록 => 두개씩만 수록


    int count = 1; //각 장르별로 몇개 수록됐는지(2개만 수록할 수 있음, 3되면 break.
    int play, idx; 
    for (int i = 0; i < genres_sum.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            if (count == 3) break;  //장르별 2개만 가능으로 3이면 반복문 탈출
            if (count == 1) { //처음에
                play = v[j].first; //재생횟수
                idx = v[j].second.first; //고유번호
            }
            if (genres_sum[i].second == v[j].second.second) { //장르일치. 
                // 2번째로 수록할 곡.  재생횟수 일치  + 앞에 저장된 고유번호가 이제 발견한 것보다 더 크면 순서 바꿔줌
                if (count == 2 && play == v[j].first && idx > v[j].second.first) {
                    int tmp = answer.back(); //맨뒤
                    answer.pop_back();
                    answer.push_back(v[j].second.first); //고유번호 저장
                    answer.push_back(tmp);
                }
                else { //첫번째로 수록하거나 재생횟수가 같지 않거나 장르와 재생횟수가 일치하는데 고유번호순서가 낮은 거부터 수록됐으면
                    answer.push_back(v[j].second.first); //그대로 저장
                }
                count++;
            }
        }
        //장르 하나끝날때마다 count 1로 초기화
        count = 1;
    }

    return answer;
}