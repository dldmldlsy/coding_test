#include <string>
#include <vector>

using namespace std;

int solution(int N, int number) {
    int answer = 0;
    //dp의 핵심은 메모이제이션: 무엇을 dp에 저장할지, 어떻게 중복을 최소화할지. 
    //
    return answer;
}

#include <vector> 
#include <unordered_set>
using namespace std; 
int getNN(int N, int idx) { 
    int result = N; 
    for (int i = 1; i <= idx; i++) {
        result = result * 10 + N; 
    } return result; 
} 
int solution(int N, int number) { 
    if (N == number) return 1; 
    vector<unordered_set<int>> DP(8); 
    DP[0].insert(N); 
    for (int k = 1; k < 8; k++) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) { 
                if (i + j + 1 != k) continue; 
                for (int a : DP[i]) {
                    for (int b : DP[j]) { 
                        DP[k].insert(a + b);
                        if (a - b > 0) 
                            DP[k].insert(a - b); 
                        DP[k].insert(a * b); 
                        if (a / b > 0) 
                            DP[k].insert(a / b); 
                    }
                }
            }
        }
        DP[k].insert(getNN(N, k)); 
        if (DP[k].count(number)) 
            return k + 1; 
    }
    return -1; 
}
