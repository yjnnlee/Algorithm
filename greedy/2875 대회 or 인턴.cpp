#include <stdio.h>
#include <algorithm>
using namespace std;
int n, m, k, go = 0;
int main() {
	scanf("%d%d%d", &n, &m, &k);
	while (go != k) {
		if (m * 2 > n) { //남자가 더 많으면
			--m; //남자를 뺀다
			++go;
		}
		else { //9 5
			--n;
			++go;
		}
	}
	if (m * 2 < n) printf("%d", m);
	else printf("%d", n / 2);
}
