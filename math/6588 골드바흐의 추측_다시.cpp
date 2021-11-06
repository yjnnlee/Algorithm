#include <iostream>
using namespace std;
const int MAX = 1000000;
int prime[MAX];
int pn;
bool check[MAX+1];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 2; i <= MAX; i++) {
        if (check[i] == false) {
            prime[pn++] = i; //이 수는 소수이다
            for (int j = i + i; j <= MAX; j += i) {
                check[j] = true; //배수는 전부 삭제한다
            }
        }
    }
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        //소수A+B=N소수. B는 소수?
        //즉, N-A=B는 소수? chk에 false=소수가 맞다 -> 출력
        for (int i = 1; i < pn; i++) {
            if (check[n - prime[i]] == false) {
                cout << n << " = " << prime[i] << " + " << n - prime[i] << '\n';
                break;
            }
        }
    }
}
