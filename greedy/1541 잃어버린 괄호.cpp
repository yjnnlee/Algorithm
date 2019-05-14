#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int n, sum = 0, tmpsum = 0;
char a[105];

int main() {	
	scanf("%[^\n]s", a);
	int len  = strlen(a), k = 0;
	bool minus = 0;
	for (int i = 0; i < len+1; i++) {
		if ('0' <= a[i] && a[i] <= '9') {
			k *= 10;
			k += a[i] - '0';
		}
		else if (a[i] == '+') {
			tmpsum += k;
			k = 0;
//			printf("%d\n", tmpsum);
		}
		else {
			tmpsum += k;
			if (minus) { //앞쪽이 빼기였으면 빼야함
				sum -= tmpsum;
			}
			else { //앞쪽이 더하기였으면 더해야함
				sum += tmpsum;
			}
			/*10+20-30+40-10과 10+20-30+40+10은 값이 같음
			10-10-10-10과 10-10+10+10도 값이 같음
			즉, 맨 처음 -가 나오기 전까지 다 더하고 그 이후는 +든 -든 다 빼면됨ㅋㅋ
			*/
			minus = 1;
			tmpsum = 0;
			k = 0;
		}
	}
	printf("%d", sum);
}

/*
10+20-30+40-10
1. 숫자로 변환하다가 +가 나오면 자릿수 초기화하고 sum에 더함
2. -가 나오면 그 다음 -전까지 다 더하고 sum값에서 뺌
*/
