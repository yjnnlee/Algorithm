#include <stdio.h>
int n, year;
char a[20] = "ABCDEFGHIJKL";
char b[20] = "01234567890";
int main() {
	scanf("%d", &n);
	n += 56;
	n %= 60;

	printf("%c%c", a[n % 12], b[n % 10]);
}
