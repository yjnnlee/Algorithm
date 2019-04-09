#include <stdio.h>

int n, res = 1, chk[205];
struct {
	int first;
	int second;
}a[55];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].first, &a[i].second);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) { /*!chk[a[j].first]*/ 
			if (a[i].first < a[j].first && a[i].second < a[j].second) {
				res++;
				//chk[a[j].first] = 1;
			}
		}
		printf("%d ", res);
		res = 1;
	}
}
