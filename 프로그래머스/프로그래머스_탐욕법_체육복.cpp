#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int studentN = n; 
    vector<int> lost_num;
    vector<int> reserve_num = reserve; 
    int count = studentN - lost.size(); //현재 체육복을 갖고 있는 학생 수 
    cout << count << endl;
    for (vector<int> ::iterator i = lost.begin(); i < lost.end(); i++) { //안가져온 학생 번호의 배열을 돌면서 
       // cout << "그냥" << *i << endl;
        bool self = false;

        for (vector<int> ::iterator iter = reserve_num.begin(); iter < reserve_num.end(); iter++) {
            if (*i == *iter ) {
               // cout << *iter << endl;
                reserve_num.erase(iter); 
                count++; self = true;
                break; 
            }
        }
        if (!self) lost_num.push_back(*i);
       // cout << "!" << endl;
    }
   // cout << ": " << lost_num.size() << endl;
    for (int i = 0; i < lost_num.size(); i++) { //안가져온 학생 번호의 배열을 돌면서 
        for (vector<int> ::iterator iter = reserve_num.begin(); iter < reserve_num.end(); iter++) {
            if (lost_num[i] == *iter - 1 || lost_num[i] == *iter + 1) {
              // cout << *iter << endl;
                reserve_num.erase(iter); count++;
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