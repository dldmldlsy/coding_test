#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int studentN = n;  //학생수
    // lost: 도난당한 학생 번호 배열
    vector<int> lost_num; // 여벌옷이 없는데 도난당한 학생 번호 배열 
    vector<int> reserve_num = reserve; // 여별옷을 가져온 학생 번호 배열 
    int count = studentN - lost.size(); //수업을 들을 수 있는 학생 수 = 현재 체육복을 갖고 있는 학생 수 (학생수-잃어버린 학생수)  
    for (vector<int> ::iterator i = lost.begin(); i < lost.end(); i++) {  //도난당한 학생 번호의 배열을 돌면서 
        bool self = false; // 자기여벌을 자기가 가졌는지. 

        for (vector<int> ::iterator iter = reserve_num.begin(); iter < reserve_num.end(); iter++) {   //여벌옷을 가진 학생 번호를 돎
            if (*i == *iter ) { // 같은 번호가 있으면 -> 자기 여벌옷을 자기가 가짐 
               // cout << *iter << endl;
                reserve_num.erase(iter);  // 여벌옷을 가진 학생 번호 배열에서 해당 번호를 지움. 
                count++; self = true; // 수업 들을 수 있는 학생 수 +1, 자기 여벌을 자기가 가졌으니 true로 바꿈.  
                break; //반복문 탈출
            }
        }
        if (!self) lost_num.push_back(*i); // false=>  도난당했는데여벌을 가지고 있지않은 학생이므로 lost_num에 추가. 
    }
    for (int i = 0; i < lost_num.size(); i++) {
        cout << lost_num[i] << " ";
    }
    cout << endl;
    sort(lost_num.begin(), lost_num.end());
    for (int i = 0; i < lost_num.size(); i++) {
        cout << lost_num[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < lost_num.size(); i++) { //도난당한 학생 번호의 배열을 돌면서 
        for (vector<int> ::iterator iter = reserve_num.begin(); iter < reserve_num.end(); iter++) { //여벌옷가져온 학생번호배열을 돎. 
            if (lost_num[i] == *iter - 1 || lost_num[i] == *iter + 1) { //도난당한 학생번호가 여벌옷가져온 학생번호-1 or +1일일때
                reserve_num.erase(iter); count++; //여벌옷을 해당학생에게 주므로 여벌학생번호에서 지우고, count증가. 
                break;
            }
        }
    }
    answer = count;
    return answer;
}
int main() {
    cout<<"총"<<solution(5, {2,4}, {1,3,5});
}