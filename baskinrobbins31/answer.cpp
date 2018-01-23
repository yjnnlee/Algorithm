#include <stdio.h>
#define nm 10000001

long long int r, q, a, b, sum = nm, n, s;

int main() {
	//FILE *fp1, *fp2;
	//fp1 = fopen("09.out", "w");

	scanf("%lld", &n);

	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &a, &b);

		q = (((a - ((a - 1) % (b + 1))) / (b + 1) + 1) * 2);
		if (q < sum) {
			s = i + 1;
			sum = q;
		}
	}
	printf("%lld %lld", s, sum);
	//fprintf(fp1, "%lld %lld", s, sum);
	//fclose(fp1);
	return 0;
}

//14429
