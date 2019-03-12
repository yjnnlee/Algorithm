#include <stdio.h>
#include <string.h>
char a[1005];
int main() {
	while (1) {
		fgets(a, 1000, stdin); //c언어에선 이제 fgets를 써야
		if (a[0] == 'E' && a[1] == 'N' && a[2] == 'D') break; //개행문자가 있어서 strcmp를 못쓰니까 하나씩
		int len = strlen(a);
		for (int i = 0; i < len; i++) {
			if (a[len - i - 1] == '\n') continue; //개행문자도 받아버리니 개행없애줌
			printf("%c", a[len - i - 1]);
		}
		printf("\n");
	}
}
