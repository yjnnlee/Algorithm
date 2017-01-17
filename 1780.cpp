#include <stdio.h>

int n, m[3000][3000], res[3];

void solve(int x, int y, int size) {
	int paper = m[y][x];
	int same = true;
	
	for (int i = y; (i < y + size) && same; i++) { //위부터 아래까지 같으면 계속가고 틀리면 빠져나옴
		for (int j = x; (j < x + size) && same; j++) { //왼쪽부터 오른쪽까지
			if (paper != m[i][j]) { //배열의 x, y번째 비트랑 검사한 곳이랑 다르면 아래서 분할 
				same = false; 
			}
		}
	}
	if (same) res[paper+1]++; //같으면 개수를 셈
	else { //아니면 분할
		solve(x, y, size / 3); //왼쪽 위
		solve(x + (size / 3), y, size / 3); //중간 위
		solve(x + (size / 3) * 2, y, size / 3); //오른쪽 위

		solve(x, y + (size / 3), size / 3); //왼쪽 중간
		solve(x + (size / 3), y + (size / 3), size / 3); //중간 중간
		solve(x + (size / 3) * 2, y + (size / 3), size / 3); //오른쪽 중간

		solve(x, y + (size / 3) * 2, size / 3); //왼쪽 아래
		solve(x + (size / 3), y + (size / 3) * 2, size / 3); //중간 아래
		solve(x + (size / 3) * 2, y + (size / 3) * 2, size / 3); //오른쪽 아래
	}
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &m[i][j]);
		}
	}
	solve(0, 0, n);
	
	for (int i = 0; i < 3; i++) {
		printf("%d\n", res[i]);
	}
}