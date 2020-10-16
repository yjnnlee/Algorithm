#include <stdio.h>
#define size 1000003
int a[size], sosu[size];
bool chk = false;
int tmp, n;
int main() {
	for (int i = 2; i * i <= size; i++) {
		if (!a[i]) {
			for (int j = i * i; j <= size; j += i) {
				a[j] = 1;
			}
		}
	}
	a[1] = 1;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &tmp);

		for (int i = tmp / 2; i > 0; i--) {
			if (!a[i] && !a[tmp - i]) {
				printf("%d %d\n", i, tmp - i);
				break;
			}
		}
	}
}
