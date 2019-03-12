#include <stdio.h>
int e, s, m, ee = 0, ss = 0, mm = 0, res = 0;
int main() {
	scanf("%d%d%d", &e, &s, &m);
	while (1) {
		if (ee == 16) ee = 1; //나눠지면 돌려야함
		if (ss == 29) ss = 1;
		if (mm == 20) mm = 1;
		if (ee == e && ss == s && mm == m) break;
		ee++, ss++, mm++, res++;
	}
	printf("%d", res);
}
