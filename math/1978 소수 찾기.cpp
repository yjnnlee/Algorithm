#include <stdio.h>
int num, i, m, sum = 0;
int f(int num) {
	for (i = 2; i < num; i++) {
		if (num%i == 0) break;
	}
	if (num == i) return 1;
	else return 0;
}

int main() {
	scanf("%d", &num);
	for (int j = 0; j < num; j++) {
		scanf("%d", &m);
		if (f(m)) sum++;
	}
	printf("%d", sum);
}
