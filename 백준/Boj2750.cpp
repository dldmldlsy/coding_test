//#include<iostream>
//#include<queue>
//using namespace std;
//int main() {
//	int n;
//	priority_queue<int> pq;
//
//	cin >> n; int x;
//	while (n--) {
//		cin >> x;
//		pq.push(x);
//	}
//	while (n--) {
//		cout << pq.top() << endl;
//		pq.pop();
//	}
//}

#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n; 
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
  
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				int x = a[i];
				a[i] = a[j];
				a[j] = x;
		
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << endl;
}