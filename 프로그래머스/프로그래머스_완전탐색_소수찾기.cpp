#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;
bool isPrimeNumber(int x) {
    if (x <= 1)
        return false;
    int end = x/2;
    for (int i = 2; i <=end; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}
int solution(string numbers) { //0~9 숫자로 구성.  1~7길이
    int answer = 0;
    vector<char> num;
    for (int i = 0; i < numbers.length(); i++) {
        num.push_back(numbers.at(i));
    }
   int n= numbers.length();
   vector<int> v;
       sort(num.begin(), num.end());
       do {
           string s= "";
           for (int i = 0; i < num.size(); i++){
               s += num[i];
               v.push_back(stoi(s));
           }
         } while (next_permutation(num.begin(), num.end()));

       sort(v.begin(), v.end());
       v.erase(unique(v.begin(), v.end()),v.end());

       for (int i = 0; i < v.size(); i++) {
           if (isPrimeNumber(v[i]))
           {
               answer++;
           }
       }
    return answer;
}
int main() {
    cout<<solution("011");
}
