#include <stdio.h>
#include <algorithm>


using namespace std;
int n, k, d[300005], chk[100005], time[100005];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i <= n; i++) {
		d[i] = n - i;
	}

	if (n > k) {
		printf("%d", abs(k - n));
	}
	else if (n == k) {
		printf("0");
	}
	else {
		for (int i = n + 1; i <= k; i++) {
			if (i - 1 >= n) {
				if (i % 2 == 0) { //짝수면 그냥 두 배
					d[i] = min(d[i-1]+1, d[i / 2] + 1);
				}
				else { //홀수면 올리든 내리든 돌아와야 해서 2번 더 움직임
					//예를 들어 11이라면 5를 두배하고 +1이거나 6을 두배하고 -1이지만 둘 다 두번 움직임
					d[i] = min(d[i-1]+1, min(d[i / 2] + 2, d[(i + 1) / 2] + 2));
					//현재 위치까지의 최소 거리 = 지금 vs 지금 전 칸 vs 지금 다음 칸에 갈 경우(+1)
				}
			}
		}
		printf("%d", d[k]);
	}
}

//망한코드
//#include <stdio.h>
//#include <queue>
//#include <memory.h>
//using namespace std;
//
//int a, b, cnt= 0;
//
//int main() {
//	scanf("%d%d", &a, &b);
//	while (1) {
//		if (a == b) break;
//		cnt++;
//		if (a * 2 <= b) {
//			a *= 2;
//		}
//		else {
//			if ((abs(b - ((a - 1) * 2)) < abs(b - ((a + 1) * 2))) &&
//				((a - 1) * 2 < b || (a + 1) * 2) < b) a--;
//			else if ((abs(b - ((a - 1) * 2)) > abs(b - ((a + 1) * 2))) &&
//				((a - 1) * 2 < b || (a + 1) * 2) < b) a++;
//			else if (abs(b - (a - 1)) < abs(b - (a + 1))) {
//				a--;
//			}
//			else a++;
//		}
//	}
//	printf("%d", cnt);
//}
