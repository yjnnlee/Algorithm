#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
long long sum[31];
int main() {
	int d, k;
	cin >> d >> k;
	sum[d] = k;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k; j++) {
			sum[1] = i; sum[2] = j;
			for (int p = 3; p <= d; p++) {
				sum[p] = sum[p - 2] + sum[p - 1];
			}
			if (sum[d] == k) {
				//for (auto x : sum) {
				//	cout << x << " ";
				//}
				//cout << endl;
				cout << sum[1] << "\n" << sum[2];
				return 0;
			}
			else {
				memset(sum, 0, sizeof(sum));
			}
		}
	}
}
