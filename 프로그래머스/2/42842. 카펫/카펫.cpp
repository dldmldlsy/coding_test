#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    //w: 가로, h: 세로
    int w, h; 
    //brown=w*h-(w-2)*(h-2)=2w+2h-4, yellow= (w-2)*(h-2)=w*h-brown
    //brown+yellow=w*h 
    //2(w+h)=brown+4
    //w+h=brown/2+2
    //w((brown/2)+2-w)=brown+yellow -> w 알 수 있음!
    
    int all = brown + yellow; 
    
    //w찾기
    for (int i = 1; i <= all; i++) {
        if (all % i == 0) { 
            if (i * (brown / 2 + 2 - i) == all)
            {
                w = i;  break;
            }
        }
    }
    //h
    h = brown / 2 + 2 - w;
    //가로 >= 세로 조건 충족 
    if (w < h) {
        int tmp = w;
        w = h;
        h = tmp;
    }
    // 가로, 세로 넣어서 반환
    answer.push_back(w); answer.push_back(h);
    
    return answer;
}