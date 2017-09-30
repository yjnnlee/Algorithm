#include <iostream>
using namespace std;

int w, h, map[51][51], res = 0;

void dfs(int x, int y) {
	map[x][y] = 0;

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			int a = x + i;
			int b = y + j;

			if (map[a][b] == 1) { 
				dfs(a, b); 
			}
		}
	}
}

int main() {
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1) {
					dfs(i, j);
					res++;
				}
			}
		}
		cout << res << "\n";
		res = 0;
	}
}
