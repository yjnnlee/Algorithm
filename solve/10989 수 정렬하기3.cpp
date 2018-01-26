#include <stdio.h>
#include <algorithm>
using namespace std;
int n, a[10007], t;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		a[t] += 1;
	}

	for (int i = 1; i <= 10000; i++) {
		if (a[i] != 0) {
			if (a[i] == 1) {
				printf("%d\n", i);
			}
			else {
				for (int j = 1; j <= a[i]; j++) {
					printf("%d\n", i);
				}
			}
		}
	}
}
