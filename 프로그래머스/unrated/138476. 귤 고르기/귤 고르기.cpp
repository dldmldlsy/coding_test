#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> m; //귤 크기별 개수 [크기, 개수]
    
    for(int i=0; i<tangerine.size(); i++){
        m[tangerine[i]]++;
    }
    
    vector<int> v;
    map<int, int>::iterator iter; 
    for(iter = m.begin(); iter!=m.end(); iter++){
        v.push_back((*iter).second); 
    }
    sort(v.begin(), v.end(), greater<int>());
    
    int cnt = 0; 
    for(int i=0; i<v.size(); i++){
        if(cnt>=k) break;
        answer++; //종류 수
        cnt+=v[i]; //담은 귤 수 
    }
    
    return answer;
}