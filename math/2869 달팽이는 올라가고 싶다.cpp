#include <stdio.h>
int a, b, v;

int main() {
	scanf("%d %d %d", &a, &b, &v);
	/*끝까지 올라온 날은 -b를 하지 않으므로
	총 올라간 미터는는 v-b미터여야 한다
	v-b미터가 a-b미터로 딱 나눠지면 마지막 날에 끝난 것
	아니면 하루 더 가야한다 정답+1

	3 1 6 -> 3일(222)
	2 1 5 -> 4일(1112)
	*/
	int res = (v - b) / (a - b);
	printf("%d", (v - b) % (a - b) ? res + 1 : res);

}
