#include <stdio.h>
#include <math.h>
int n, r, c, res = 0, limt;

//int pow(int a, int b) { //제곱
//	for(int i=0;i<b;i++) a *= a;
//	return a;
//}

void visit(int x, int y, int size, int cnt) {
	/*if (size == 2) {
		if (x == c && y == r) { printf("%d", res); return; } res++;
		if (x + 1 == c && y == r) { printf("%d", res); return; } res++;
		if (x == c && y + 1 == r) { printf("%d", res); return; } res++;
		if (x + 1 == c && y + 1 == r) { printf("%d", res); return; } res++;
		return;
	}*/
	if (size == 0 && x == r && y == c) {
		printf("%d", cnt);
		return;
	}
	if (x > r || x + size * 2 <= r || y > c || y + size * 2 <= c) return;

	//if (limt / 2 > c && limt / 2 > r) visit(size, x, y);
	//if (limt / 2 < c && limt / 2 > r) {
	//	res = pow(limt / 2, 2);
	//	visit(size / 2, x + size / 2, y);
	//}
	//if (limt / 2 > c && limt / 2 < r) {
	//	res = 2 * (pow(limt / 2, 2));
	//	visit(size / 2, x, y + size / 2);
	//}
	//if (limt / 2 < c && limt / 2 < r) {
	//	res = 3 * (pow(limt / 2, 2));
	//	visit(size / 2, x + size / 2, y + size / 2);
	//}

	int newsize = size * size;
	//printf("1: %d %d %d %d\n", x, y, size / 2, cnt);
	//printf("2: %d %d %d %d\n", x + size, y, size / 2, cnt + newsize);
	//printf("3: %d %d %d %d\n", x, y + size, size / 2, cnt + newsize * 2);
	//printf("4: %d %d %d %d\n\n", x + size, y + size, size / 2, cnt + newsize * 3);
	visit(x, y, size/2, cnt);
	visit(x, y + size, size / 2, cnt + newsize);
	visit(x + size, y, size/2, cnt + newsize*2);
	visit(x + size, y + size, size/2, cnt + newsize * 3);
}

int main() {
	scanf("%d %d %d", &n, &r, &c); //r이 가로 c가 세로
	visit(0, 0, pow(2,n), 0);
}
