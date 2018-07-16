#include <stdio.h>

int main() {
	//1 2 3 4 5 6 넣고 싶은데
	int a[3000];
	//scanf("%s", a); //정확히 나옴
	for (int i = 1; i <= 6; i++) {
//		scanf("%c", &a[i]); //1 2 3밖에 안 나옴
//		scanf("%c ", &a[i]); //1 2 3 4 5 6 + 뭔가를 하나 더 넣어야 함
		  scanf(" %c", &a[i]); //<<<<<<이거 됨
	}
	for (int i = 1; i <= 6; i++) {
		printf("%c ", a[i]);
	}
}
