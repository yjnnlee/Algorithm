#include <stdio.h>
int n, res;
char a[20];

int main() {
	for (int i = 0; i < 3; i++) {
		scanf("%s", &a);
		for (int j = 0; j < 8; j++) {
			n = 1;
			for (int k = j + 1; k < 8; k++) {
				if (a[j] == a[k]) n++;
				else break;
			}
			if (res < n) res = n;
		}
		printf("%d\n", res);
		res = 0;
	}
}
