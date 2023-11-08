//프로그래머스 0단계 홀짝 구분하기
#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    cin >> n;    
    if(n%2==0){
        cout<<n<<" is even\n"; 
    }else{
        cout<<n<<" is odd\n";
    }
    return 0;
}