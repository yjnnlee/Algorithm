//#include <stdio.h>
//#include <algorithm>
//using namespace std;
//int n, a[40000], len, res = 0, now = 0;
//
//int main() {
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &a[i]);
//	}
//
//	for (int i = 1; i < n; i++) {
//		scanf("%d", &len);
//		if (a[i - 1] + len > now) {
//			now = a[i - 1] + len;
//			//printf("%d\n", now);
//		}
//		if (now < a[i]) {
//			printf("엄마 나 전역 늦어질 것 같아");
//			return 0;
//		}
//	}
//	printf("권병장님, 중대장님이 찾으십니다");
//}


#include <stdio.h>
#include <algorithm>
using namespace std;
int n, a[40000], len, res = 0, now = 0;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 1; i < n; i++) {
		scanf("%d", &len);
		for (int j = i; j < n; j++) {
			if (a[i - 1] + len > a[j]) {
				now = max(now, a[i]);
				//printf("%d\n", now);
				break;
			}
		}
	}

	if (n == 1 || now >= a[n - 1]) printf("권병장님, 중대장님이 찾으십니다");
	else printf("엄마 나 전역 늦어질 것 같아");
}
