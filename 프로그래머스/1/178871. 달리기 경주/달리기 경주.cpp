#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string, int> m; 
    
    for(int i=0; i<players.size(); i++){
        m[players[i]]=i; 
    }
    
    for(string overName: callings){
        int overNum = m[overName];
        int backNum = overNum-1; 
        string backName = players[backNum]; 
        swap(players[backNum], players[overNum]);
        swap(m[overName], m[backName]);        
    }
    answer = players;
    return answer;
}