#include <stdio.h>
int a, b, c, d, who;
int attack(int who, int x, int y) {
	int sum = 0, now = -1; // -1이 x -2가 y
	while (1) {
//		printf("%d %d %d\n", sum, now, who);
		if (sum >= who) {
			if (now == -1) return 0; //바꿔졌던거 감안해서 돌려서 반환
			else return 1;
		}
		if (now == -1) {
			sum += x;
			now = -2;
		}
		else {
			sum += y;
			now = -1;
		}
	}
}

int main() {
	scanf("%d%d%d%d", &a, &b, &c, &d);
	for (int i = 0; i < 3; i++) {
		scanf("%d", &who);
		printf("%d\n", attack(who, a, b)+attack(who, c, d));
	}
}
