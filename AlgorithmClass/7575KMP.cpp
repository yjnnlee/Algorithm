#include <stdio.h>
#include <algorithm>
using namespace std;

int n, k, m;
int pi[1001], num[1001];

int generate_pi(int num[], int pi[]) {
	int p = sizeof(num)/sizeof(int);
	//int형 4바이트 * 배열 개수 / int형 4바이트 = 배열 길이
	pi[0] = 0;
	int j; //인덱스

	for (int i = 1; i < p; i++) {
		while (j > 0 && num[i] != num[j]) {
			//숫자 일치하지 않으면서 j가 0이 아닐 때까지(무슨 의미?)
			j = pi[j - 1];
		}

		if (num[i] == num[j]) {
			//일치하면 j값을 늘림
			++j;
		}
		pi[i] = j;

	}
}

int kmp(int k, int num[]) {

}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		for (int j = 0; j < m; j++) {
			scanf("%d", &num);
		}
		generate_pi(num, pi);
		kmp(k, num);

	}
}