#include <iostream>
using namespace std;
int n, m, map[1025][1025];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); //시간초과 방지
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp;
			cin >> tmp;
			map[i + 1][j + 1] = map[i][j + 1] + map[i + 1][j] - map[i][j] + tmp;
		}
	}
	for (int i = 0; i < m; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << map[x2][y2] - map[x1 - 1][y2] - map[x2][y1 - 1] + map[x1 - 1][y1 - 1] << '\n';
	}
}

/*
#include <stdio.h>
using namespace std;
int n, m, map[1025][1025];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp;
			scanf("%d", &tmp);
			map[i + 1][j + 1] = map[i][j + 1] + map[i + 1][j] - map[i][j] + tmp;
		}
	}
	for (int i = 0; i < m; i++) {
		int x1, x2, y1, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", map[x2][y2] - map[x1 - 1][y2] - map[x2][y1 - 1] + map[x1 - 1][y1 - 1]);
	}
}

*/
