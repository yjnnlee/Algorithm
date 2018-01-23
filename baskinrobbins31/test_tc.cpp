#include <stdio.h>
int main(){
	int m[1000][2];
	FILE *f = fopen("00.in", "r");
	int n;
	fscanf(f, "%d", &n);
	for (int i = 1; i < n; i++) {
		fscanf(f, "%d %d", &m[i][0], &m[i][1]);
	}

	printf("%d\n", n);
	for (int i = 1; i < n; i++) {
//		printf("%d %d\n", m[i][0], m[i][1]);
		if ((m[i][0] - 1) % (m[i][1] + 1) == 0) { //배수면 안됨
			printf("[배수오류] %d: %d %d\n", i, m[i][0], m[i][1]);
		}
		if (m[i][0] <= m[i][1]) { //오른쪽이 더 크거나 같은 수면 안됨
			printf("[j<m] %d: %d %d\n", i, m[i][0], m[i][1]);
		}
	}
	fclose(f);
	return 0;
}
