#include <stdio.h>
#include <stdlib.h>

int n, queen[20], res = 0;

bool CanIGo(int y) {
	for (int i = 0; i < y; i++) { //다 돌필요 없음
		if (queen[y] == queen[i] || abs(queen[i] - queen[y]) == y - i) {
			return false;
		}
	}
	return true;
}

void board(int y) { //한줄에 하나씩이라 행은 필요없음
	if (y == n -1) {
		res++;
	}
	else{
		for (int i = 0; i < n; i++) {
			queen[y +1] = i; //같은줄은 어차피 안됨
			if (CanIGo(y + 1)) { //갈수있나?
				board(y + 1); //고고
			}
		}
	}
}

int main() {
	scanf("%d", &n);

	board(-1);

	printf("%d", res);
}
