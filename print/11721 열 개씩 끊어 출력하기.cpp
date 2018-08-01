#include <stdio.h>
#include <string.h>
int main() {
	int n = 0;
	char a[1000];
	scanf("%s", a);
	for (int i = 0; i < strlen(a); i++) {
		if (n < 10) {
			printf("%c", a[i]);
			n++;
		}
		else {
			printf("\n");
			i--;
			n = 0;
		}
	}
}
