//백준 2231번
//단계별 - 브루트포스
//분해합 - correct!
#include<iostream>
#include<string> //to_string
#include<vector>  //vector
#include<algorithm> //sort
using namespace std;
int main() {
	int n;
	cin >> n; 
	int sum;  //string 216
	vector<int> v; 
	for ( int i = 1; i < n; i++) { //i: 198 198+1+9+8=216
		sum = i;
		string s = to_string(i);
		int len = s.length(); 
		for (int j = 0; j < len; j++) {
			char c = s.at(j); 
			int num = c - '0'; 
			sum += num; 
		}
		if (sum == n)
			v.push_back(i);
	}
	if (v.empty()) cout << 0; 
	else {
		sort(v.begin(), v.end());
		cout << v[0];
	}
}