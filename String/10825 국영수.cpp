#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<pair<string, pair<int, pair<int, int>>>> v; //이름, 국, 영, 수

bool cmp(pair<string, pair<int, pair<int, int>>>x, pair<string, pair<int, pair<int, int>>>y) {
    if (x.second.first != y.second.first) return x.second.first > y.second.first; //국어 점수가 감소하는 순서로
    else if (x.second.first == y.second.first && x.second.second.first != y.second.second.first) return x.second.second.first < y.second.second.first; //국어 점수가 같으면 영어 점수가 증가하는 순서로
    else if (x.second.first == y.second.first && x.second.second.first == y.second.second.first && x.second.second.second != y.second.second.second) return x.second.second.second > y.second.second.second; //국어 점수와 영어 점수가 같으면 수학 점수가 감소하는 순서로
    else return x.first < y.first; //모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로 (단, 아스키 코드에서 대문자는 소문자보다 작으므로 사전순으로 앞에 온다.)
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    while (n--) {
        int a, b, c;
        string s;
        cin >> s >> a >> b >> c;
        v.push_back({ s,{a,{b,c}} });
    }
//    cout << v[0].first << " " << v[0].second.first << v[0].second.second.first << " " << v[0].second.second.second;
    stable_sort(v.begin(), v.end(), cmp);
    for(auto x: v) {
        cout << x.first << "\n";
    }
}
