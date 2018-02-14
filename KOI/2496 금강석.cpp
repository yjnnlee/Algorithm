#include <stdio.h>
#include <algorithm>
using namespace std;

int w, h, num, k;
int res[1000], height = 0, height2 = 0;
struct P {
	int x, y;
};
P map[10000];
int cmp(P a, P b) {
	if (a.x != b.x) return a.x < b.x;
	else return a.y < b.y;
}

int main() {
	scanf("%d%d%d%d", &w, &h, &num, &k);
	for (int i = 0; i < num; i++) {
		scanf("%d%d", &map[i].x, &map[i].y);
	}
	//	sort(map, map + num, cmp); //cmp 알아두기

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (map[j].x >= map[i].x - k / 2 && map[j].x <= map[i].y + k / 2
				&& map[j].y >= map[i].y - k / 2 && map[j].y <= map[j].y + k / 2) {
				res[i]++;

				//if (!(map[j].x - k / 2 < map[i].x && map[j].y - k / 2 < map[j].y - k / 2)
				//	&& !(map[j].x + k / 2 > map[j].x && map[j].y + k / 2 > map[j].y)) {
				for (int t = map[j].x - k / 2 + 1; t <= map[j].x - 1; t++) {
					for (int r = 0; r < num; r++) {
						if (map[r].x = t) {
							if (map[r].y > map[j].y + height || map[r].y < map[j].y - height) {
								res[i]--;
							}
						}
						height++;
					}
				}
				for (int t = map[j].x + 1; t <= map[j].x + k/2 - 1; t++) {
					for (int r = 0; r < num; r++) {
						if (map[r].x = t) {
							if (map[r].y > map[j].y + height || map[r].y < map[j].y - height) {
								res[i]--;
							}
						}
						height--;
					}
				}
			}
		}
	}

	int max = 0, xy = 0;
	for (int i = 0; i < num; i++) {
		if (res[i] > max) {
			max = res[i];
			xy = i;
		}
	}
	printf("%d %d\n%d", map[xy].x, map[xy].y, max);
}
