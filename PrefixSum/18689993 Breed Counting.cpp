#include <stdio.h>
using namespace std;
int n, m, sum[3], map[100001][3];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);

        map[i][0] = map[i - 1][0]; //모든 값을 다 채워주기 위해
        map[i][1] = map[i - 1][1];
        map[i][2] = map[i - 1][2];

        if (a == 1) map[i][0] = ++sum[0];
        if (a == 2) map[i][1] = ++sum[1];
        if (a == 3) map[i][2] = ++sum[2];
    }

    for (int i = 0; i < m; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%d %d %d\n", map[e][0]-map[s-1][0], map[e][1] - map[s - 1][1], map[e][2] - map[s - 1][2]);
    }
}
