#include <stdio.h>
int a, b, c, d, who;
int attack(int who, int x, int y) {
	int sum = 0, now = -1; // -1이 x -2가 y
//		printf("%d %d %d\n", sum, now, who);
	while(1){
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
/*
2 3 2 3
2 3 6

1번 사람은 2분에 오는데 sum에 2를 더하면 시간에 겹쳐진다
2번 사람은 3분에 오는데 sum에 2+3을 더하면 시간 안에 3분이 들어간다
3번 사람은 6분에 오는데 sum에 2+3+2를 더하는 순간 시간 안에 6분이 들어간다

sum에 a와 b를 번갈아가면서 더하다가 sum값이 오는 시간을 같거나 넘는 순간에서
개가 무는지 안무는지를 확인한다

now가 a를 더할지 b를 더할지 확인해주는 변수

근데 예제와 같이 a와 b의 값이 같은 경우 now는 b를 가리키고 있는데 a에서 걸려버린다
그래서 now를 아예 없는 숫자 -1, -2로 해줬고 -1인 경우는 a니까 +=x를 해준 것

한 가지 주의할 점은 무조건 now를 바꿔버리기 때문에 sum에 걸렸을 시점은
now를 바꾸기 전에 걸린 것이라 return을 이전꺼로 해줘야함
*/
}

int main() {
	scanf("%d%d%d%d", &a, &b, &c, &d);
	for (int i = 0; i < 3; i++) {
		scanf("%d", &who);
		printf("%d\n", attack(who, a, b)+attack(who, c, d));
	}
}
