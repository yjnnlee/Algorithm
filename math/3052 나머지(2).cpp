#include <stdio.h>
int arr[42], k, count = 0;

int main(){
	for (int i = 0; i<10; i++) {
		scanf("%d", &k);
		arr[k % 42]++;

	}
	for (int i = 0; i<42; i++) {
//		printf("%d ", arr[i]);
		if (arr[i] >= 1) count++;
	}
	printf("%d", count);
}
