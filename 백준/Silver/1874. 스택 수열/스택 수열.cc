#include<iostream>
#include<stack>
using namespace std;
int main() {
    stack<int> s;
    int n; bool ok = true;
    string ans= "";
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int cur = a[0]; int f = 0;
    for (int i = 1; i <= cur; i++) {
        s.push(i); ans+="+\n";
        f = i;
    }
    s.pop(); ans+="-\n";
    int next;
    for (int j = 0; j < n - 1; j++) {
        cur = a[j];
        next = a[j + 1];
        if (cur < next) {
            int i = f; int num = next - f;
            while (num--) {
                i++;
                s.push(i); ans+= "+\n";
                          }
            f = i;
            s.pop(); ans+="-\n";
        }
        else if (cur > next) {
            if (s.top() == next) {
                s.pop(); ans+= "-\n";
            }
            else {
                ok = false; break;
            }
        }
    }
    if (!ok) cout << "NO\n";
    else cout << ans;
}