//백준 1316번
//단계별 - 문자열
//그룹단어체커 -correct!
#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;  string s; int num; //그룹단어개수
	int size = 'z' - 'a'+1;
	char c; int index;
	int count = n;
	while (n--) {
		cin >> s; 
		vector<int> v(size, 0);
		for (int i = 0; i < s.length(); i++) {
			 index =  s.at(i)- 'a';
			if (v[index] == 0) { //h a p 
				v[index] = 1;
				int j = index;
				bool last = false; 
				while (j == index) {
					if (i == (s.length() - 1)) { last = true;  break; }
					i++; 
					j = s.at(i) - 'a';
				}
				if(!last) i--;
			}
			else if (v[index]==1) {
				count--; break;
			}
		}
	}
	cout << count;
}