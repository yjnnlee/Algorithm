#include <stdio.h>

int n, a;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (!(a&(a - 1))) printf("1\n"); 
		else printf("0\n");
	}
}
