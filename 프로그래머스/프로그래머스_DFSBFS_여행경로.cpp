#include <string>
#include <vector>
#include<map> //map�̿�(���׸� ����)
#include<algorithm> //sort�̿�. 
using namespace std;
struct path {//��θ� ��Ÿ���� ����ü (�ڷ���)����
    string s; //��������
    bool used = false;
};
bool cmp(path& a, path& b) {
    return a.s < b.s; //���ĺ��� ���� ������ ����
}; 

map<string, int> m; //���׸�, ��ȣ ����. 
vector<path> v[10001]; //v[��߰��׹�ȣ]=��������. 
vector<string> answer; //���� ��ΰ� ��� ����

path tmp; //��θ� ��Ÿ���� ����ü���� tmp����. (��������)
int N; //solution���� ���� dfs������ �� �Ŷ� ��������. 
bool finish = false;



void dfs(int idx);
vector<string> solution(vector<vector<string>> tickets) {
    
    N = tickets.size(); //Ƽ�ϰ���, �װ��ǰ���

    int num = 0;

    //tickets�迭 ���鼭 �Ʒ� �۾� �ݺ�. 
    //: (m(���׸��� ��ȣ����), v(��߰��׹�ȣ->�������׸�=> �����������) )
    for (int i = 0; i < N; i++) { 
        string s1 = tickets[i][0]; //��߰���
        string s2 = tickets[i][1]; //��������
        if (m[s1] == 0) m[s1] = ++num; //��ȣ�� �Ⱥپ������� ���׸� ��ȣ�ְ�, ��ȣ����. 
        if (m[s2] == 0) m[s2] = ++num; 
        tmp.s = s2;  //tmp�� s�� �������׸�����. 
        v[m[s1]].push_back(tmp); //v[m[��߰��׸�]]=�������׸� => v[��߰��׹�ȣ]=�������׸�
    }

    //��������� ����� v���͸� (�������׸���)���ĺ����ڰ� ���� ������ (��������) ����.
    for (int i = 1; i <= num; i++) {
        sort(v[i].begin(), v[i].end(), cmp);
    }
    answer.push_back("ICN"); //�׻� ICN���׿��� ���. 
    dfs(1); 
    return answer;
}


void dfs(int idx) {
    if (finish) return;  //finish�� true�� �Լ� ����
    if (idx > N) { //idx�� Ƽ�ϼ��� �ʰ��ϸ� 
        finish = true;  
        return; //�Լ�����
    }
    string cur = answer[idx - 1]; 
    //������Ʈ������ ������׸��� ��� ���� cur. 
    //index�� idx-1�� answer�� ���ҿ��� ���׸��� ������� 
    //��ó�� dfs(1)=> idx=1=> answer[1-1]=answer[0]=ICN=> cur=ICN

    int val = m[cur]; //val=m[���� ���׸�]=�ش� ���׸��� ��ȣ

    //�ش� ���׸��� ��ȣ�� ���� ������ ��߰������� �ϴ� �װ���(v[val])�� �� ���鼭 �ݺ�
    for (int i = 0; i < v[val].size(); i++) {
        if (v[val][i].used) continue; // �̹� ������ �������� !
        v[val][i].used = true; //�Ȱ����� used�� true�� �ٲ���. 
        string next = v[val][i].s; //��������
        answer.push_back(next); //�������׸��� ������ι迭�� answer�� ����. 
        dfs(idx + 1); //���� ��ȣ�� ���� dfs. 
        if (finish) return;//�������� dfs�Լ� ����. 
        answer.pop_back();//�ȳ������� �߸��� ���ϱ� ������ �� ����
        v[val][i].used = false; //�������� �湮���ߴٰ� �ٽ� �ٲ��ְ� ��
        //���� i�� �� �� .
    }
}