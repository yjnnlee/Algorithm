#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n;

int main() {
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	vector<int> segtree;

	sort(a.begin(), a.end());


}