#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    string odd = "", even = "";
    for(auto num: num_list){
        if(num%2==0){
            even += num+'0';
        }else{
            odd += num+'0';
        }
    }
    answer = stoi(odd)+ stoi(even);
    return answer;
}