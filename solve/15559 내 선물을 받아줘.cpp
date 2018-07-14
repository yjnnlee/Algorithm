#include <stdio.h>
int n;
char a[3000];
int main() {
	scanf("%d", &n);
	scanf("%s", a);
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 'E' && a[i+1] == 'W') {
			res++;
		}
	}
	printf("%d", res);
}
