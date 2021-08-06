//#include <string>
//#include <vector>
//#include<algorithm>
//using namespace std;
//
//string solution(string number, int k) {
//    string answer = "";
//    int len = number.length(); 
//    int num = len - k; 
//    vector<char> v; 
//    for (int i = 0; i < len; i++) {
//        v.push_back(number[i]);
//    }
//    sort(v.begin(), v.end());
//    vector<char> vv;
//    for (int i = 0; i <k; i++) {
//        vv.push_back( v[len-1-i]);
//    }
//
//    for (int i = 0; i < len; i++) {
//        for (int j = 0; j < vv.size(); j++) {
//            if (number[i] == vv[j]) {
//                answer += vv[j];
//            }
//        }
//    }
//    return answer;
//}

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string number, int k) {
	string answer = "";
	int n = number.length() - k; //문자열 길이-제거할 수 = 최종 문자열길이

	 //ex 1231234=> 총 4글자만들어야하면  
	// 1231 중에 제일 큰 수 3
	// 12 12 중에 제일 큰 수 2 
	// 1""""123
	int max = 0; 
	int count = 0;
	int j;
	vector<int> v;
	for (int i = n; i > 0; i--) {
		max = 0;
		count = 0;
		//큰수찾기. 
		for (j = 0; j < number.length() - i + 1; j++) {
			if (max < number[j]) {
				max = number[j];
				count = j;
			}
		}
		number.replace(0, count + 1, " ");  // index가 0인 것부터 count+1개를 공백으로 치환

		v.push_back(max);
	}
	for (int i = 0; i < v.size(); i++)
		answer += v[i];
	return answer;
}