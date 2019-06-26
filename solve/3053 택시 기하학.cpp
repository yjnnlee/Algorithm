#include <stdio.h>
int n;
int main(void) {
	scanf("%d", &n);
	printf("%.6lf\n%.6lf", (double)(n*n*3.14159265358979323846264338327950288), (double)(2*n*n));
	return 0;
}
