#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string word;
	cin >> word;
	
	int alpa[26];
	fill_n(alpa, 26, -1); 
	
	for (int i = 0; i < word.size(); i++) {
		if (alpa[word[i] - 'a']==-1) {
			alpa[word[i] - 'a'] = i;
		}
	}
	for (auto x : alpa) {
		cout << x << " "; 
	}
}