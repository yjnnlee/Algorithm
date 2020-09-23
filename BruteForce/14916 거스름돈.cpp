#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, sum = 0;
    cin >> n;
    if (n == 1 || n == 3) {
        cout << "-1";
        return 0;
    }
    if (n % 5 % 2 == 0) {
        sum = n / 5 + n % 5 / 2;
    }
    else {
        sum = n / 5 + (n % 5 + 5) / 2 - 1;
    }

    cout << sum;
    return 0;
}

//다른 다양한 방법 https://foxtrotin.tistory.com/319
