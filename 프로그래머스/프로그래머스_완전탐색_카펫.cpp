#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int w, h; 
    //brown=w*h-(w-2)*(h-2)=2w+2h-4, yellow= (w-2)*(h-2)=w*h-brown
    //brown+yellow=w*h 
    //2(w+h)=brown+4
    //w+h=brown/2+2
    //w((brown/2)+2-w)=brown+yellow
    int b = brown + yellow; 
    for (int i = 1; i <= b; i++) {
        if (b % i == 0) {
            if (i * (brown / 2 + 2 - i) == b)
            {
                w = i;  break;
            }
        }
    }
    h = brown / 2 + 2 - w;
    if (w < h) {
        int tmp = w;
        w = h;
        h = tmp;
    }
    answer.push_back(w); answer.push_back(h);
    return answer;
}