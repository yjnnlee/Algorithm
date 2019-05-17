#include <stdio.h>
int n = 1e9, num, sum  = 0;
int main(){
	for (int i = 0; i < 7; i++) {
		scanf("%d", &num);
		if (num % 2) {
			sum += num;
			if (n > num) n = num;
		}
	}
	if (sum == 0) printf("-1");
	else printf("%d\n%d", sum, n);
}
