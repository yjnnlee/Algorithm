#include <stdio.h>
int n;
char a, b, c, tree[1000][2];

void print(int x, int i) {
	if (i == 0) printf("%c", x); //전위면 먼저 출력하고 탐색
	if (tree[x][0] != '.') print(tree[x][0], i); //왼쪽 자식이 있다면 내려감
	if (i == 1) printf("%c", x); //중위면 왼쪽 갔다가 출력
	if (tree[x][1] != '.') print(tree[x][1], i);
	if (i == 2) printf("%c", x); //후위면 다 탐색하고 출력
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %c %c %c", &a, &b, &c);
		tree[a][0] = b, tree[a][1] = c;
	}
	for (int i = 0; i < 3; i++) {
		print('A', i);
		printf("\n");
	}
}
