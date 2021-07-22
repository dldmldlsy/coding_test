//#include <string>
//#include <vector>
//#include<algorithm> //정렬
//using namespace std;
//
//bool solution(vector<string> phone_book) {
//    bool answer = true;
//    sort(phone_book.begin(), phone_book.end());
//    for (int i = 0; i < phone_book.size() - 1; i++) {
//        for (int j = i+1; j < phone_book.size(); j++) {
//            if (phone_book[i] == phone_book[j].substr(0, phone_book[i].length()))
//                return false;
//        }
//    }
//   
//    return answer;
//}

//벡터로 풀었더니 정확도는 통과됐는데 효율성에서 실패. 
//해시로 푸니까 효율성도 통과. 

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    string str = "";
    unordered_map<string, int> d;

    for (auto& i : phone_book) {
        str = "";
        for (int j = 0; j < i.size(); j++) {
            str += i[j];
            d[str]++;
        }
    }

    for (auto& i : phone_book) {
        if (d[i] > 1) {
            answer = false;
            break;
        }
    }
    return answer;
}
