#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<pair<int, string>>v;

bool cmp(pair<int, string>x, pair<int, string>y) {
    return x.first < y.first;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    while (n--) {
        int a;
        string s;
        cin >> a >> s;
        v.push_back({ a,s });
    }
    //sort함수->두 원소가 같을 때 기존의 순서를 유지해준다는 보장이 없다
    //정석대로는 second도 비교해 주어야 하는데, stable_sort를 사용할 수도 있다(메모리 엄청 먹음)
    stable_sort(v.begin(), v.end(), cmp);
    for(auto x: v) {
        cout << x.first << " " << x.second << "\n";
    }
}
