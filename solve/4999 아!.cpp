#include <stdio.h>
#include <string.h>
char a[1005], b[1005];
int main() {
	scanf("%s%s", a, b);
	if (strlen(a) >= strlen(b)) printf("go");
	else printf("no");
}
