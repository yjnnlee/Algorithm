#include <stdio.h>
int n, arr[100005], max = 0, cnt = 0, jj;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (arr[i] > arr[j]) cnt++;
			else {
//				jj = j;
				break;
			}
		}
		if (max < cnt) {
			max = cnt;
//			i = jj;
		}
		cnt = 0;
	}
	printf("%d", max);
}
