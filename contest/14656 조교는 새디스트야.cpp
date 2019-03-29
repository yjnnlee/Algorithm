#include <stdio.h>
int n, arr[20005], cnt=0;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i] != i) cnt++;
	}
	printf("%d", cnt);
}
