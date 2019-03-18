#include <stdio.h>
int n;
void move(int n, int x, int y) { //n: 움직여야 할 원판의 높이, x: 현재 자리, y: 옮겨갈 자리
	if (n == 0) return;
	move(n - 1, x, 6-x-y);
	printf("%d %d\n", x, y);
	move(n - 1, 6 - x - y, y);
}
int main() {
	scanf("%d", &n);
	printf("%d\n", (1<<n)-1); //항상 2^n -1 만큼 움직임
	move(n, 1, 3);
}
