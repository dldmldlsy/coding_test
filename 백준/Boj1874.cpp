//#include<iostream>
//#include<stack>
//using namespace std;
//int main() {
//	stack<int> s;
//	int n;
//	cin >> n;
//	int* a = new int[n];
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	int cur = a[0];
//	for (int i = 1; i <= cur; i++){
//		s.push(i); cout << "+" << endl;
//}
//	s.pop(); cout << "-" << endl;
//	int next = a[1];
//	if (cur < next) {
//
//	}
//}

2

2

2





1

1

1

1





여기서 4 출력               3 출력                       6 출력                        5가 출력이 되어야 한다.



만일 다른 숫자가 들어온다면 ? "NO"를 출력하며 함수가 끝나도록 구현.






2. 소스코드

처음 구현

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
#include<iostream>
#include<stack>

int main() {
    int n, x, max(0);
    std::cin >> n;

    std::stack<int> s;
    while (n--) {
        std::cin >> x;
        if (x > max) {
            for (int i = max + 1; i <= x; i++) {
                s.push(i);
                std::cout << "+\n";
            }
        }
        else
            if (s.top() != x) {
                std::cout << "NO";
                return 1;
            }
        s.pop();
        std::cout << "-\n";
        if (max < x) max = x;
    }

    return 0;
}
Colored by Color Scripter
cs


오류 수정("NO"의 경우에 '+'와 '-'는 출력이 되면 안되는 것이였다.)

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
#include<iostream>
#include<stack>

int main() {
    char sol[200050];
    int solptr(0);
    int n, x, max(0);
    std::cin >> n;

    std::stack<int> s;
    while (n--) {
        std::cin >> x;
        if (x > max) {
            for (int i = max + 1; i <= x; i++) {
                s.push(i);
                sol[solptr++] = '+';
            }
        }
        else
            if (s.top() != x) {
                std::cout << "NO";
                return 0;
            }
        s.pop();
        sol[solptr++] = '-';
        if (max < x) max = x;
    }
    for (int i = 0; i < solptr; i++) std::cout << sol[i] << "\n";

    return 0;
}
