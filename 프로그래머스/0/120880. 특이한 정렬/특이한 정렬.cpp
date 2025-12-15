#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// numlist를 n 기준으로 정렬한 결과를 반환하는 함수
vector<int> solution(vector<int> numlist, int n) {
    // 사용자 정의 정렬을 수행
    sort(numlist.begin(), numlist.end(), [n](int &a, int &b){
        int diffA = abs(n - a); // a와 n의 거리 계산
        int diffB = abs(n - b); // b와 n의 거리 계산

        if(diffA == diffB)       // 거리가 같다면
            return a > b;        // a가 클때 true 반환
        return diffA < diffB;    // a의 거리가 가까울 때 true 반환
    });

    return numlist; // 정렬된 numlist를 반환
}