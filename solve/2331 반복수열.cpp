#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <memory.h>
#include <math.h>
using namespace std;

vector<long long> res;
int n, m;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int cnt = 0;
    cin >> n >> m;
    res.push_back(n);
    string s = to_string(n);
    //반례 153 3, 1 1 처럼 시작하자마자 반복되는 수(답이 0인 수 처리)
    while (1) {
        long long next = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            next += (int)pow(s[i] - '0', m);
        }
        for (int i = 0; i < res.size(); i++) {
            if (res[i] == next) {
                for (int j = 0; j < i; j++) cnt++;
                cout << cnt;
                return 0;
            }
        }
        res.push_back(next);
        s = to_string(next);
    }
}
