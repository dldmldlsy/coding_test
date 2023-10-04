#include <string>
#include <vector>
#include <map>
#include <sstream>
#include<cmath> //ceil

using namespace std;

int time_diff(string, string); //주차시간계산(출차-입차)
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    map<string, vector<string>> m; // 차량별 주차내역시간저장할 map 생성
    
    stringstream ss; 
    //공백기준으로 문자열 분리-> 차량번호, 주차시간, 입출차구분 
    for(auto record: records){
        ss.str(record);
        string time, number, status; 
        ss>>time>>number>>status; 
        //차량번호에 따른 시간 저장
        m[number].push_back(time);
        ss.clear(); 
    }
    
    for(auto iter: m){
        if(iter.second.size()%2==1){ // 주차내역 개수가 홀수면 -> 23:59 추가 
            iter.second.push_back("23:59");
        }
        vector<string> info = iter.second;
        int total = 0; //누적시간 
        //두개씩 짝지어서 주차시간 누적 계산
        for(int i=0; i<info.size()-1; i+=2){
            total += time_diff(info[i], info[i+1]); 
        }
        int fee = fees[1]; 
        if(total>fees[0]){ //기본시간초과 
            fee += ceil((total-fees[0])/(double)fees[2])*fees[3];  
            //기본 요금 + 추가 요금 계산 (올림)
        }
        //기본시간 이하-> 그대로 기본 요금 
        answer.push_back(fee);
    }
    return answer;
}
int time_diff(string in, string out){
    int h1 = stoi(in.substr(0, 2));
    int m1 = stoi(in.substr(3, 2)); 
    int h2 = stoi(out.substr(0, 3));
    int m2 = stoi(out.substr(3, 2));
    
    int diff = (h2-h1)*60+(m2-m1);
    
    return diff;
}