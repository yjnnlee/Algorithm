#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
struct A {
	int start, end;
}a[100005];

bool cmp(const A &first, const A &second) {
	if (first.end == second.end) return first.start < second.start;
	else return first.end < second.end;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].start, &a[i].end);
	}
	sort(a, a + n, cmp);
	//for (int i = 0; i < n; i++) {
	//	printf("%d %d\n", a[i].start, a[i].end);
	//}
	int last = 0, res = 0;
	for (int i = 0; i < n; i++) {
		if (a[i].start >= last) {
			last = a[i].end;
			res++;
//			printf(">%d %d %d\n", a[i].start, a[i].end, last);
		}
	}
	printf("%d", res);
}	
