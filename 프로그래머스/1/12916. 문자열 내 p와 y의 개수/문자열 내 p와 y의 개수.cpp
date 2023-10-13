#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int cntP =0, cntY = 0; 
    for(auto ss: s){
        if(ss=='p'||ss=='P'){
            cntP++;
        }
        if(ss=='y'||ss=='Y'){
            cntY++;
        }
    }
    if(cntP!=cntY){
        answer=false;
    }
    return answer;
}