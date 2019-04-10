#include <stdio.h>
#include <algorithm>
using namespace std;
int n, s, a[25], sum = 0, res = 0;

int main() {
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	/*n=5면 <32(31)까지, n=3이면 7까지 반복->모든 부분 집합 전부 검사, 공집합은 없으니까 1부터 시작
	왜 전부 검사가 되냐면 001 = A, 010 = B, 011 = A/B, 100 = C, 101 = C/A, 110 = C/B, 111 = A/B/C 총 7개라서
	*/
	for (int i = 1; i < (1<<n); i++) {
		for (int j = 0; j < n; j++) { //부분 집합의 값을 더함
//			printf("i: %d, j: %d, (1<<j): %d\n", i, j, 1 << j);
			if (i & (1 << j)) {
				sum += a[j]; //1<<n의 의미=1*2^n
//				printf("\n>%d\n", sum);
			}
		}
		if (sum == s) res++;
		sum = 0;
	}
	printf("%d", res);
}
