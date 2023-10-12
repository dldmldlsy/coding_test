#include <string>
#include <vector>
#include <iostream>

using namespace std;

string changeTwo(int);
vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0; 
    int zero = 0;
    string tmp = "";
    int len;
    while(s!="1"){
        //0 제거
        for(auto c: s){
            if(c=='0'){
                zero++;
            }else{
                tmp+=c;
            }
        }        
        len = tmp.size(); 
        tmp="";
        s = changeTwo(len);
        cout<<s<<endl;
        cnt++;
    }
    
    answer.push_back(cnt); 
    answer.push_back(zero);
    
    return answer;
}
// n(10)->2진법으로 변환
string changeTwo(int n){
    vector<int> v; 
    while(n){
        v.push_back(n%2); 
        n /= 2; 
    }
    string result = ""; 
    
    for(auto one : v){
        result += to_string(one); 
    }
    return result;     
}