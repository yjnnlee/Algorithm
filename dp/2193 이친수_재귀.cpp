#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
int f(int i, int what) {
	int cnt = 0;
	if (i == n) {
		return 1;
	}
	if (what == 1) cnt+=f(i + 1, 0);
	if (what == 0) {
		cnt+=f(i + 1, 1);
		cnt+=f(i + 1, 0);
	}
}
int main() {
	scanf("%d", &n);
	printf("%d", f(1, 1)); //1번째 자리는 무조건 1
}
