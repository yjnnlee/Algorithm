#include <stdio.h>
int c, n, score[1005], cnt = 0;
double avg = 0;
int main() {
	scanf("%d", &c);
	while (c--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &score[i]);
			avg += score[i];
		}
		avg /= n;
		for (int i = 0; i < n; i++) {
			if (score[i] > avg) cnt++;
		}
		printf("%.3f%%\n", (double)cnt * 100 / n);
		cnt = 0, avg = 0;
	}
}
