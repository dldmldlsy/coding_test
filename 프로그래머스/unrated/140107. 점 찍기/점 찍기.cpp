#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    for(int i=0; i<=d; i+=k){
        long long dis = (long long) d*d -(long long)i*i;//(b*k)^2 
        answer += floor(sqrt(dis)/k)+1; //제곱근 -> k로 나눔 -> 내림 (자연수여야하므로)
    }
    return answer;
}