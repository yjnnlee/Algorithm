#include <stdio.h>
#include <string.h>
char a[5][16];
int len, tmp;

int main() {
	for (int i = 0; i < 5; i++) {
		scanf("%s", &a[i]);
		tmp = strlen(a[i]);
		if (tmp > len) {
			len = tmp;
		}
	}	

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 5; j++) {
			if (a[j][i] >= 'A' || a[j][i] <= 'Z' || a[j][i] >= 'a' || a[j][i] <= 'z' || a[j][i] >= 0 || a[j][i] <= 9){
				if (a[j][i] != NULL) {
					printf("%c", a[j][i]);
				}
			}
		}
	}
}
