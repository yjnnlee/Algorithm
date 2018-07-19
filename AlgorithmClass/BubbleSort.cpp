#include <stdio.h>
#include <algorithm>
using namespace std;

int a[100], n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n -1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		printf("%d", a[i]);
	}
}