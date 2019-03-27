#include <stdio.h>
int n,m;
int gcd(int a, int b) {
	if (b == 0) return a;
	gcd(b, a%b);
}
int main() {
	scanf("%d:%d", &n, &m);
	int g = gcd(n, m);
	printf("%d:%d", n/g, m/g);
}
