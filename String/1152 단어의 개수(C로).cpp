#include <stdio.h>
#include <string.h>
char a[1000005];
int main() {
	scanf("%[^\n]s", a);
	int len = strlen(a), res = 0;
	if ((len == 1 && a[0] == ' ') || len == 0) {
		//뒤에서 맨 마지막 단어 있다고 가정하고 1더할껀데 애초에 아무것도 없으면 0으로 끝내야함
		printf("0");
		return 0;
	}

	for (int i = 0; i < len; i++) {
		if ((i == 0 && a[i] == ' ') || (i == len - 1 && a[i] == ' ')) continue;
		if (a[i] == ' ') res++;
	}
	printf("%d", res+1); //맨 마지막 단어 더하기
}
