#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[10003];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        a[x]++;
    }

    for (int i = 1; i <= 10000; i++) {
        if (a[i] != 0) {
            if (a[i] == 1) cout << i << "\n";
            else {
                for (int j = 0; j < a[i]; j++) cout << i << "\n";
            }
        }
    }
}
