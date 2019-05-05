#include <stdio.h>
int n, m, c;
int main() {
	scanf("%d %d %d", &n, &m, &c);
	m += c;
	if (m >= 60) {
		n += m/60;
		m %= 60;
	}
	if (n >= 24) {
		n %= 24;
	}
	printf("%d %d", n, m);
}
