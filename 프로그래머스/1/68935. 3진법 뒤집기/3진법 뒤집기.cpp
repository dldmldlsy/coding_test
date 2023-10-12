#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> reverseThree; 
    //n(10)->3진법 역순 저장
    while(n){
        reverseThree.push_back(n%3); 
        n = n/3;
    }
    
    //다시 10진법으로 변환 
    int multiplier = 1; 
    for(int i= reverseThree.size()-1; i>=0; i--){
        answer += reverseThree[i]*multiplier;
        multiplier *= 3; 
    }
    return answer;
}