#include <stdio.h>
#include <stdlib.h>
int n, queen[20][20]; 
int res= 0;

bool CanIGo(int x, int y) {
	if (x == 0) return true; //처음은 무조건 가능

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (queen[i][j] == true && (i == x || j == y || abs(i - x) == abs(j - y))) {
				return false;
			}
		}
	}

	return true;
}

void board(int x) {
	for (int y = 0; y < n; y++) {
		if (CanIGo(x, y)) {
			queen[x][y] = 1;
			if (x == (n - 1)) { //끝까지 다 찾으면
				res++;
				queen[x][y] = false;
			}
			else {
				board(x + 1);
				queen[x][y] = false;
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	queen[0][0] = 1;

	board(0);
	
	printf("%d", res);

}
