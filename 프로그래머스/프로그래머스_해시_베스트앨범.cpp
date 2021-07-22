#include <string>
#include <vector>
#include<map>
#include<algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<pair<int, pair<int, string>>> v; //���Ƚ��, ������ȣ, �帣 ����. 
    for (int i = 0; i < genres.size(); i++) {
        v.push_back(make_pair(plays[i], make_pair(i, genres[i]))); // Ƚ��, (������ȣ, �帣) 
    }
    // ���Ƚ���� ������������( �帣 ������ ���� ����� �뷡 ����) 
    sort(v.begin(), v.end()); 
    reverse(v.begin(), v.end()); 
   
    //���� �뷡�� ���� ����� �帣 ->  �帣���Ϳ��� �ߺ� ���Ұ� ����������. 
    sort(genres.begin(), genres.end()); 
    genres.erase(unique(genres.begin(), genres.end()), genres.end()); 
    //unique() 

    vector<pair<int, string>> genres_sum; //�帣��(�����, �帣) 

    //�帣�� ���Ƚ�� ��ġ��
    for (string g : genres) { //�ߺ����Ҿ��� �帣���� �ϳ��� ���鼭(=�� �帣)
        int sum = 0;
        for (int i = 0; i < v.size(); i++) { //�� �뷡���鼭 �ش��帣 ���Ƚ�� ��ġ��
            if (g == v[i].second.second) { //�ش��帣�� �� ������ �ι�°(���) �ι�°����(=�帣)�� ���ٸ� 
                sum+=v[i].first; //���Ƚ�� ���ϱ� 
            }
        }
        genres_sum.push_back(make_pair(sum, g)); //�帣���������, �帣 ����

    }

    //�帣�� ����� ���� ����� ������ ���� (��������)
    sort(genres_sum.begin(), genres_sum.end());
    reverse(genres_sum.begin(), genres_sum.end());

    //�� �帣�� ������̵ɼ���, ������ȣ ���� ���� ���� ���� => �ΰ����� ����


    int count = 1; //�� �帣���� � ���ϵƴ���(2���� ������ �� ����, 3�Ǹ� break.
    int play, idx; 
    for (int i = 0; i < genres_sum.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            if (count == 3) break;  //�帣�� 2���� �������� 3�̸� �ݺ��� Ż��
            if (count == 1) { //ó����
                play = v[j].first; //���Ƚ��
                idx = v[j].second.first; //������ȣ
            }
            if (genres_sum[i].second == v[j].second.second) { //�帣��ġ. 
                // 2��°�� ������ ��.  ���Ƚ�� ��ġ  + �տ� ����� ������ȣ�� ���� �߰��� �ͺ��� �� ũ�� ���� �ٲ���
                if (count == 2 && play == v[j].first && idx > v[j].second.first) {
                    int tmp = answer.back(); //�ǵ�
                    answer.pop_back();
                    answer.push_back(v[j].second.first); //������ȣ ����
                    answer.push_back(tmp);
                }
                else { //ù��°�� �����ϰų� ���Ƚ���� ���� �ʰų� �帣�� ���Ƚ���� ��ġ�ϴµ� ������ȣ������ ���� �ź��� ���ϵ�����
                    answer.push_back(v[j].second.first); //�״�� ����
                }
                count++;
            }
        }
        //�帣 �ϳ����������� count 1�� �ʱ�ȭ
        count = 1;
    }

    return answer;
}