#include <stdio.h>
int n, m, c, d;
int main() {
	scanf("%d %d %d %d", &n, &m, &c, &d);
	c += d;
	if (c >= 60) {
		m += c / 60;
		c %= 60;
	}
	if (m >= 60) {
		n += m/60;
		m %= 60;
	}
	if (n >= 24) {
		n %= 24;
	}
	printf("%d %d %d", n, m, c);
}
