#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
//소수 판별
bool isPrime(long long num){
    if(num<2) return false; 
    for(int i=2; i<=sqrt(num); i++){
        if(num%i==0){
            return false;// 나눠지면 소수 x
        }
    }
    return true; //소수
}

int solution(int n, int k) {
    int answer = 0; 
    
    vector<pair<string, int>> v; 
    
    //k진수로 변환
    
    string s ="";
    while(n>0){
        s+= to_string(n%k); 
        n/=k; 
    }
    
    reverse(s.begin(), s.end());
    
    string tmp = ""; 
    for(char c: s){
        if(c=='0'){
            if(!tmp.empty()&& isPrime(stoll(tmp))){
                answer++; //소수 개수 
            }
            tmp=""; 
        }
        else tmp+= c; 
    }
    
    if(!tmp.empty() && isPrime(stoll(tmp))){
        answer++; 
    }
    
    return answer;
}