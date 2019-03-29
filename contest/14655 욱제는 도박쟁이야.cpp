#include <stdio.h>
#include <algorithm>
using namespace std;
int n, num, sum1 = 0,sum2=0;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		sum1 += abs(num);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		sum2 += abs(num);
	}
	printf("%d", sum1 - (-sum2));
}
