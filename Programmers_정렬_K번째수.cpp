#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	vector<int> v; int x;
	while (n--) {
		cin >> x;  v.push_back(x);
	}
	vector<int> r;
		while (v.size() != 0) {
			int m = *v.begin();
			for (vector<int>::iterator iter = v.begin(); iter < v.end(); iter++) {
				if (m < *iter) {
					m = *iter;
				r.push_back(m);
				v.erase
			}
		}
	
}