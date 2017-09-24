#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int n, i, v, e, res;

int main() {
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d %d", &v, &e);
		res = v - e - 2;
        printf("%d\n", abs(res));
	}
}

#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//int n, i, v, e, res[101];
//
//int main() {
//	scanf("%d", &n);
//
//	for (i = 0; i < n; i++) {
//		scanf("%d %d", &v, &e);
//		res[i] = v - e - 2;
//	}
//
//	for (int i = 0; i < n; i++) {
//		printf("%d\n", abs(res[i]));
//	}
//}
