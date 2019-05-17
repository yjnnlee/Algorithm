#include <stdio.h>
int num, n[10], res = 0, chk[1001];
int main(){
	for (int i = 0; i < 10; i++) {
		scanf("%d", &num);
		n[i] = num % 42;
	}
	for (int i = 0; i < 10; i++) {
		if (!chk[n[i]]) {
			res++;
			chk[n[i]] = 1;
		}
	}
	printf("%d", res);
}
