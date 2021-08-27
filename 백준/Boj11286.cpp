//백준11286번
//우선순위큐-절댓값힙
//시간초과ㅠㅠ... 이게 안되는 이유는 뭘까?? 
//pair로 하면 되는데 이게 안되는 이유부터 찾기. 
#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
bool cmp(int a, int b) {
	if (abs(a) == abs(b)) return a < b;
	return abs(a) < abs(b);
}
int main() {
	ios_base::sync_with_stdio(0);

	cin.tie(0);

	int n; 
	cin >> n; 
	int tmp;
	deque<int> d;
	while (n--) {
		cin >> tmp;
		if (tmp != 0) {
			d.push_back(tmp);
			sort(d.begin(), d.end(), cmp);
		}
		else {
			if (d.empty()) cout << 0 << "\n";
			else { cout << d.front() << "\n";  d.pop_front(); }
		}
	}

}