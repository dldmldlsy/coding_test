//백준 15596번
//단계별 -함수
//정수 N개의 합
#include<iostream>
#include<vector>
using namespace std;
long long sum(vector<int>& a) {
	long long result = 0;

	for (vector<int>::iterator iter = a.begin(); iter < a.end(); iter++)
		result += *iter;

	return result;
}
