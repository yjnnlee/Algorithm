#include <stdio.h>
#include <algorithm>
using namespace std;
int h[105], sum = 0;

int main() {
	for (int i = 0; i < 9; i++) {
		scanf("%d", &h[i]);
		sum += h[i];
	}
	sort(h, h + 9);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {			
			if (i == j) continue;
			int a = h[i] + h[j];
			if (sum - a == 100) {
				h[i] = 0, h[j] = 0;
				goto exit;
			}
		}
	}
exit:
	for (int i = 0; i < 9; i++) {
		if(h[i] != 0) printf("%d\n", h[i]);
	}
}
