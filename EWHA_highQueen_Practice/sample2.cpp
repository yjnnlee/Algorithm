#include <stdio.h>
int c, m, now = 0, res= 0;
int change, money[] = { 500,100,50,10,5,1 };

int main() {
	scanf("%d%d", &c, &m);
	c = c - m;
	change = c;

	while (change > 0) {
		if (money[now] <= change) {
			res++;
			change -= money[now];
		}
		else now++;
	}

	printf("%d", res);
}
