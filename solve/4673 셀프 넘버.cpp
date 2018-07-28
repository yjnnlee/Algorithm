#include <stdio.h>
int num, res[10003], index = 0, self[10003]; //2는 셀프 넘버, 셀프면 1

int main() {
	for (int i = 1; i <= 10000; i++) {
		if (self[i] == 0) {
			res[index++] = i;
			for (int j = i; j <= 10000;) {
				num = 0;
				for (int k = j; k > 0; k /= 10) { //자릿수 나눠서 더하기
					num += (k % 10);
				}
				j += num;
				if (self[j]) break;
				if (j <= 10000) self[j] = 1;
			}
		}
	}
	for (int i = 0; i < index; i++) {
		printf("%d\n", res[i]);
	}
}
