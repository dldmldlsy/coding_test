//스터디-동적계획법

//동적계획법? 전체 문제를 작은 문제로 단순화한 후, 점화식을 통해 재귀적 구조를 활용해 해결. 

//메모이제이션(Memoization):  함수값을 계산하고 계산된 값을 배열에 저장 (필요할 때마다 함수 재호출보다 빠르게 값 가져올 수 있음) 


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
    if (N == number) { //N과 number가 동일하면 1리턴
        return 1;
    }

    int answer = -1; //우선 -1로 초기화. 

    //1. [ {} x 8 ] 초기화
    auto s = vector<set<int>>(8); //이차원배열선언. 벡터안에 셋. 
    // 2. 각 set마다 기본 수 "N" * i 수 초기화
    int idx = 1;

    for (auto& x : s) { //1행에 5, 2행에 55, 3행에 555,,,넣기
        x.insert(get_NNN(N, idx)); //(5,1) (5,2) (5, 3) (5,4) (5,5)...
        idx += 1;
    }

    //3. n 일반화
    //   { 
    //       "n" * i, 
    //       1번 set 사칙연산 n-1번 set, 
    //       2번 set 사칙연산 n-2번 set, 
    //       ...
    //       n-1번 set 사칙연산 1번 set, 
    //    } 
    // number를 가장 최소로 만드는 수 구함.
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

        if (s[i].find(number) != s[i].end()) { //그 행에 number가 있으면 
            answer = i + 1; //그 행에 N이 포함된 개수는 인덱스+1이므로 i+1. 
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