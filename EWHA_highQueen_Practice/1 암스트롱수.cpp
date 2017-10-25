#include <stdio.h>
int n, a,b,c;
bool is = false;

int f(int q) {
	return q*q*q;
}

int main() {
	scanf("%d", &n);
	//153
	for (int i = 100; i < n; i++) {
		a = i / 100;
		b = (i - a * 100) / 10;
		c = i % 10;
		
		if (f(a) + f(b) + f(c) == i) {
			printf("%d\n", i);
			is = true;
		}
	}
	if (!is) printf("0");
}
