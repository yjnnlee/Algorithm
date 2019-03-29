#include <iostream>
#include <algorithm>
using namespace std;
int n, q, arr[1005], a, b, c, d, what;
long long int sum1 = 0, sum2 = 0;

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < q; i++) {
		scanf("%d", &what);
		if(what == 1){
			scanf("%d %d", &a, &b);
			for (int j = a; j <= b; j++) sum1 += arr[j];
			printf("%lld\n", sum1);
			int tmp = arr[a];
			arr[a] = arr[b];
			arr[b] = tmp;
		}
		else {
			scanf("%d %d %d %d", &a, &b, &c, &d);
			for (int j = a; j <= b; j++) sum1 += arr[j];
			for (int j = c; j <= d; j++) sum2 += arr[j];
			printf("%lld\n", sum1 - sum2);
		}
		sum1 = 0, sum2 = 0;
	}
}
