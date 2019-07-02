#include <stdio.h>
#include <algorithm>
using namespace std;
int n, k, w[101], v[101], memo[101][100001];

int f(int i, int j) {
	int res;
	if (memo[i][j] > 0) return memo[i][j]; //계산했었다면 가져옴
	if (i == n) {
		res = 0;
	}
	else if (j < w[i]) { //들어가지 않음
		res = f(i + 1, j);
	}
	else { //들어가면
		res = max(f(i + 1, j), f(i + 1, j - w[i]) + v[i]);
	}
	return memo[i][j] = res;
}

int main(void) {
	scanf("%d%d", &n, &k);
	for (int i = 0;i < n;i++) {
		scanf("%d%d", &w[i], &v[i]);
	}
	printf("%d", f(0, k));
}
