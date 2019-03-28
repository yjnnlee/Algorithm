#include <stdio.h>
int p, n, s[108], how[108];
char what[108];
int t1 = 0, t2 = 0, t3 = 0;
double y1 = 0, y2 = 0, y3 = 0;

int main() {
	scanf("%d%d", &p, &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%s", &how[i], &what[i]);
	}

	for (int i = 1; i <= n; i++) {
		s[i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		if (what[i] == 'R') {
			for (int j = how[i] + 1; j <= 100; j++) {
				s[j] = (s[j] + 1) % 3;
			}
		}

		else if (what[i] == 'L') {
			for (int j = 1; j < how[i]; j++) {
				s[j] = (s[j] + 1) % 3;
			}
		}
	}

	for (int i = 1; i <= 100; i++) {
		if (s[i] == 0) t1 = t1 + 1;
		else if (s[i] == 1) t2 = t2 + 1;
		else if (s[i] == 2) t3 = t3 + 1;
	}

	y1 = ((double)p / 100)*t1;
	y2 = ((double)p / 100)*t2;
	y3 = ((double)p / 100)*t3;

	printf("%.2f\n", y1);
	printf("%.2f\n", y2);
	printf("%.2f", y3);
}
