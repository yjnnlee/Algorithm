#include <stdio.h>

int n, res = 0;
int price[8] = { 50000, 10000, 5000, 1000, 500, 100, 50, 10 };

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 8; i++) {
		res += n / price[i];
		n %= price[i];
	}
	printf("%d", res);
}