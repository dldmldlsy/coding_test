//���� 1021��  21.7.11
//�ܰ躰 - ť
//ȸ���ϴ� ť - correct!

//���̿�  
//�ٸ� ����� ã�ƺ���
#include<iostream>
#include<deque>
#include<vector>
using namespace std;
int main() {
	int n, m; 
	cin >> n >> m; 
	deque<int> q; //1~n���� ���
	vector<int> p; //���ϴ� ��ġ (ù ��ġ) 
	int x; //�ӽÿ��� 
	int count = 0;
	for (int i = 1; i <= n; i++)
		q.push_back(i); 
	while (m--) {
		cin >> x;  
		p.push_back(x); 
	}
	int move = 0; 
	for (int i = 0; i < p.size(); i++) {
		if (p[i] <= (n+1) / 2) {
			move = p[i] - 1;
				while (move--) {
					int f = q.front(); 
					q.pop_front(); q.push_back(f); 
					for (int j = i; j < p.size(); j++) {
						p[j] = (p[j] + n - 1) % n; if (p[j] == 0) p[j] = n;
					}
					count++; 
				} 
				q.pop_front();  n = q.size();  
				for (int j = i+1; j < p.size(); j++) {
					p[j] = (p[j] + n - 1) % n; if (p[j] == 0) p[j] = n;
				} 
		}
		else {
			move = n - p[i] + 1; 
			while (move--) {
				int b = q.back(); 
				q.pop_back(); q.push_front(b);
				for (int j = i; j < p.size(); j++) {
					p[j] = (p[j] + 1) % n; if (p[j] == 0) p[j] = n;
				}
				count++; 
			}
			q.pop_front(); n = q.size();
			for (int j = i+1; j < p.size(); j++) {
				p[j] = (p[j] + n - 1) % n; if (p[j] == 0) p[j] = n;
				
			}
		}
	}
	cout << count << endl;
}
