//쿼드압축 후 개수 세기 :: 재귀
#include <string>
#include <vector>

using namespace std;
vector<int> answer(2, 0); 

void recur(int, int, int, int, vector<vector<int>>*);
vector<int> solution(vector<vector<int>> arr) {
    int size = arr.size(); 
    recur(0, size, 0, size, &arr); 
    return answer;
}
//재귀 
void recur(int sRow, int eRow, int sCol, int eCol, vector<vector<int>> *arr){
    
    int data = (*arr)[sRow][sCol]; //대표 데이터 (영역 내 수 비교하기 위한)
    bool dividable = false; //쿼드분리여부
    
    for(int i=sRow; i<eRow && !dividable; i++){
        for(int j=sCol; j<eCol && !dividable; j++){
            if((*arr)[i][j]!=data) { //대표 데이터와 다르다면 
                dividable = true; //영역 쪼갬
            }
        }
    }
    
    if(!dividable){//쪼갤 수 없다면 하나의 수로 압축되므로 대표데이터 하나 저장
        answer[data]++;
    }else{ //쪼갤 수 있다면 -> 쿼드 분리
        recur(sRow, (sRow+eRow)/2, sCol, (sCol+eCol)/2, arr); 
        recur(sRow, (sRow+eRow)/2, (sCol+eCol)/2, eCol, arr); 
        recur((sRow+eRow)/2, eRow, sCol, (sCol+eCol)/2, arr); 
        recur((sRow+eRow)/2, eRow, (sCol+eCol)/2, eCol, arr); 
    }
}