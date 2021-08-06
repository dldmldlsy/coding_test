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
	int n = number.length() - k; //���ڿ� ����-������ �� = ���� ���ڿ�����

	 //ex 1231234=> �� 4���ڸ������ϸ�  
	// 1231 �߿� ���� ū �� 3
	// 12 12 �߿� ���� ū �� 2 
	// 1""""123
	int max = 0; 
	int count = 0;
	int j;
	vector<int> v;
	for (int i = n; i > 0; i--) {
		max = 0;
		count = 0;
		//ū��ã��. 
		for (j = 0; j < number.length() - i + 1; j++) {
			if (max < number[j]) {
				max = number[j];
				count = j;
			}
		}
		number.replace(0, count + 1, " ");  // index�� 0�� �ͺ��� count+1���� �������� ġȯ

		v.push_back(max);
	}
	for (int i = 0; i < v.size(); i++)
		answer += v[i];
	return answer;
}