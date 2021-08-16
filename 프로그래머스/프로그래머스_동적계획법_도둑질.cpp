#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {

    // vector ���� �Ҵ�
    vector<int> dp1(money.size());
    vector<int> dp2(money.size());

    // ù ��° ������ ��ĥ ���
    dp1[0] = money[0];
    dp1[1] = money[0];

    // �� ��° ������ ��ĥ ���
    dp2[0] = 0;
    dp2[1] = money[1];

    // dp1 max �� ��
    for (int i = 2; i < money.size() - 1; i++) {
        dp1[i] = max(dp1[i - 2] + money[i], dp1[i - 1]);
    }

    // dp2 max �� ��
    for (int i = 2; i < money.size(); i++) {
        dp2[i] = max(dp2[i - 2] + money[i], dp2[i - 1]);
    }

    // ���� ��ģ ��(dp1, dp2) ��
    return max(dp1[money.size() - 2], dp2[money.size() - 1]);
}