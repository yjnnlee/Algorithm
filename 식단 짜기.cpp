#include <stdio.h>

int n, a, b, c, res = 0, hungry = 0, min = 1005, tmp = 0;
//3일 굶으면 안 됨 = hungry가 3이면 안 됨
int whatmin(int x, int y) {
	if (x > y) return y;
	return x;
}
int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d%d", &a, &b, &c);
		min = (a < b ? a : b) < c ? (a < b ? a : b) : c;
		if (a == b && b == c) {
			min = a;
		}
		else if (a == b) {
			min = whatmin(b, c);
		}
		else if (b == c) {
			min = whatmin(a, c);
		}
		else if (a == c) {
			min = whatmin(a, b);
		}

		back:
		if (min == a) hungry += 0;
		else if (min == b) hungry += 1;
		else if (min == c) hungry += 2;
		
		if (hungry < 3) {
			res += min;
			hungry = 0;
			if (min == a) hungry += 2;
			else if (min == b) hungry += 1;
			else if (min == c) hungry += 0;

//			printf(">%d\n", min);
			min = 1005;
		}
		else {
			tmp++;
			if (min == a) hungry -= 0;
			else if (min == b) hungry -= 1;
			else if (min == c) hungry -= 2;
			if(tmp == 1) min = (a > b) ? ((a > c) ? ((b > c) ? b : c) : a) : ((b > c) ? ((a > c) ? a : c) : b); //두번째로 작은 값
			else if (tmp == 2) min = (a > b) && (a > c) ? a : (c > b ? c : b); //가장 큰 수
			goto back;
		}
		tmp = 0;
	}
	printf("%d", res);
}

//아침 점심 저녁으로 n일치 칼로리 정보가 들어올 때 최소한의 칼로리로 식사할껀데 연속해서 세 끼를 굶으면 안 됨
//오늘 아침 먹고 점심 저녁 내일 아침까지 패스하면 안 된다는 의미. 최대 내일 아침 이하까지(점심은 안 됨)
//근데 이 코드 100점이 아니다.. 무슨 반례가 있는건지 아직도 못 찾았다 
//같은 칼로리가 들어왔을 때, 만약 아침 점심이 같다면 아침으로 해야할지 점심으로 해야할지 처리를 못 하고 먼저 나온거로 하는데 그게 문제라고 생각만.. 
//근데 다른 사람들이 다 금방 풀었다는 걸 보면 그런 반례는 없는거 같기도 하고..
