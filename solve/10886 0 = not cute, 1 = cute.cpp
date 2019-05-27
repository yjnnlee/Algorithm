#include <stdio.h>
int n, tmp, a=0,b = 0;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		if (tmp == 0) b++;
		else a++;
	}
	if (a > b) printf("Junhee is cute!");
	else printf("Junhee is not cute!");
}
