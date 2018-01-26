#include <stdio.h>
#include <algorithm>
using namespace std;
int n, a[2000010], t;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		if (t >= 0) {
			a[t] = 1;
		}
		else {
			t = -t;
			a[t + 1000000] = 1;
		}
	}
	for (int i = 2000000; i > 1000000; i--) {
		if (a[i] != 0) {
			printf("%d\n", -(i - 1000000));
		}
	}
	for (int i = 0; i <= 1000000; i++) {
		if (a[i] != 0) {
			printf("%d\n", i);
		}
	}
}
