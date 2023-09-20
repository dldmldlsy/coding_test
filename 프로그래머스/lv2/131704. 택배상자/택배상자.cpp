#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    stack<int> s; 
    int idx =0; 
    for(int i=1; i<=order.size(); i++){
        if(i<order[idx]){
            s.push(i);
        }else if(i==order[idx]){
            answer++;
            idx++;
        }else if(i>order[idx]){
            if(!s.empty()&& s.top() == order[idx]){
                s.pop();
                idx++;
                answer++;
            }
        }else{
            break;
        }
        while(!s.empty()&& s.top()==order[idx]){
            idx++;
            answer++;
            s.pop();
        }
    }
    
    return answer;
}