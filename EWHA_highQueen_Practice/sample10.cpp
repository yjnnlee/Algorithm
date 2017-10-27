//#include <stdio.h>
////가장 긴 증가하는 부분 수열
//int n, a[1005], dp[1005];
//
//int main() {
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++) {
//		scanf("%d", &a[i]);
//	}
//	int res = 0;
//
//	for (int i = 1; i <= n; i++) {
//		int min = 0;
//		for (int j = 0; j < i; j++) {
//			if (a[j] < a[i]) { //자기보다 작은 수를 찾고
//				if (min < dp[j]) { //그놈이 지금 길이보다 크면
//					min = dp[j]; //그걸 최소로 한다
//				}
//			}
//
//			dp[i] = min + 1; //현재 위치에 1늘려줌
//			if (res < dp[i]) {
//				res = dp[i];
//			}
//		}
//	}
//
//	printf("%d", res);
//}


#include <stdio.h>
int n, a[1001], dp[1001], max = 0;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 1; i <= n; i++) {
		int min = 0;
		for (int j = 0; j < i; j++) { //DP가 처음에 0으로 시작해야 돼서 1부터 값을 받음
			if (a[j] < a[i]) {
				if (min < dp[j]) {
					min = dp[j];
				}
			}

			dp[i] = min + 1;
			if (max < dp[i]) {
				max = dp[i];
			}
		}
	}
	printf("%d", max);
}
