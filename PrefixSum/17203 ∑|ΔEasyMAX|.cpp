#include <stdio.h>
#include <algorithm>
using namespace std;
int n, m, sum[1005], map[1005];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &map[i]);
    }
    for (int i = 0; i < n; i++) {
        sum[i + 1] = abs(map[i + 1] - map[i]);
    }

    for (int i = 0; i < m; i++) {
        int s, e, res = 0;
        scanf("%d %d", &s, &e);
        for (int j = s; j <e; j++) res += sum[j];
        printf("%d\n", res);
    }
}
