#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0; 
    
    vector<int> doubleElements(elements);
    set<int> s; 
    
    //뒤에 추가해서 원형수열 만들기:: 7,9,1,1,4,7,9,1,1
    for(int i=0; i<elements.size(); i++){
        doubleElements.push_back(elements[i]);
    }
    
    vector<int> v; int num=0; 
    for(int i=0; i<elements.size(); i++){
        for(int j=0; j<elements.size(); j++){
            num=0; 
            //1~길이만큼의 수열 구해서 각 원소 더하기 
            for(int k=j;k<i+j+1; k++){ 
                num+=doubleElements[k];
            }
            v.push_back(num);
        }
        //v원소 set에 넣어서 중복 제거
        for(int j=0; j<v.size(); j++){
            s.insert(v[j]);
        }
        //vector 초기화
        v.clear();
    }
    answer = s.size();     
    return answer;
}