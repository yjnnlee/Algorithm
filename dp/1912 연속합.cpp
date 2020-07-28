#include <stdio.h>
#include <algorithm>
using namespace std;

long long int n, arr[100001], sum[100001], res = -100001;

int maxSum(long long int arr[], long long int sum[]) {
	sum[0] = arr[0];
	for (int i = 1; i < n; i++) {
		sum[i] = max(arr[i], arr[i] + sum[i - 1]);
		res = max(res, sum[i]);
	}
	res = max(res, sum[0]);
	return res;
}

int main() {
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	printf("%d", maxSum(arr, sum));
}
