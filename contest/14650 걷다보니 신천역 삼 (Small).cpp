#include <stdio.h>
#include <math.h>
int n, num, cnt = 0;

void f(int a, int len) {
	if (len == n) {
		if (a % 3 == 0 && a != 0) cnt++;
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (i == 0 && len + 1 == n) continue;
		f(i*pow(10, len) + a, len + 1);
	}
}

int main() {
	scanf("%d", &n);
	f(0, 0);
	printf("%d", cnt);
}
