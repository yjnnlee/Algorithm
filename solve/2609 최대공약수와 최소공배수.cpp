#include <stdio.h>
#include <algorithm>
using namespace std;
int a, b;
int gcd(int a, int b) {
//	printf("%d %d\n", a, b);
	if (b == 0) return a;
	gcd(b, a%b);
}
int lcm(int a, int b) {
//	printf("%d %d\n", a, b);
	return (a*b) / gcd(a, b);
}
int main() {
	scanf("%d %d", &a, &b);
	printf("%d\n%d", gcd(a, b), lcm(a, b));
}
