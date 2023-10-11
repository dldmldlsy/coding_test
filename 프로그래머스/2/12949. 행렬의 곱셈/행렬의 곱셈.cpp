//프로그래머스 - 행렬의 곱셈
// 2차원 행렬 arr1과 arr2 -> arr1*arr2 반환
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    //곱셈행렬의 크기: arr1의 행*arr2의 열 
    // 행렬의 곱셈 => 3중for문~!!
    
    for(int i=0; i<arr1.size(); i++){
        vector<int> v; 
        for(int j=0; j<arr2[0].size(); j++){
            int sum =0; 
            for(int k=0; k<arr1[0].size(); k++){
                sum+= arr1[i][k]*arr2[k][j];
            }
            v.push_back(sum);
        }
        answer.push_back(v);
    }
    return answer;
}