#include <stdio.h>
#include <string.h>
char a[1005];
int t, r;
int main() {
	scanf("%d", &t);
	while(t--){
		scanf("%d %s", &r, &a);

		int len = strlen(a);
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < r; j++) printf("%c", a[i]);
		}
		printf("\n");
	}

}
