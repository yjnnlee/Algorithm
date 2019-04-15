#include <stdio.h>
#include <string.h>
char a[105];
int n, len;

int main() {
	scanf("%s", a);
	len = strlen(a);
	for (int i = 0; i < len; i++) {
		if (a[i] >= 65 && a[i] <= 67) n += 3;
		else if (a[i] >= 68 && a[i] <= 70) n += 4;
		else if (a[i] >= 71 && a[i] <= 73) n += 5;
		else if (a[i] >= 74 && a[i] <= 76) n += 6;
		else if (a[i] >= 77 && a[i] <= 79) n += 7;
		else if (a[i] >= 80 && a[i] <= 83) n += 8;
		else if (a[i] >= 84 && a[i] <= 86) n += 9;
		else if (a[i] >= 87 && a[i] <= 90) n += 10;
		else n += 11;
	}
	printf("%d", n);
}
