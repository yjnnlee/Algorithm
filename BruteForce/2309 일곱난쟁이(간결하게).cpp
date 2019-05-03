#include <stdio.h>
#include <algorithm>
int height[10], sum = 0;
int main() {
	for (int i = 0; i < 9; i++) {
		scanf("%d", &height[i]);
		sum += height[i];
	}
	std::sort(height, height + 9);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (i != j && sum - (height[i] + height[j]) == 100) {
				height[i] = 0, height[j] = 0;

				for (int i = 0; i < 9; i++) {
					if (height[i]) printf("%d\n", height[i]);
				}
				return 0;
			}
		}
	}
}
