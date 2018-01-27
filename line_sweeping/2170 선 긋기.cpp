#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

vector<pair<int, int>> a;
int n, q, w, res = 0, r = -1e9, l = -1e9;

int main(){
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &q,&w);
		a.push_back(make_pair(q, w));
	}
	sort(a.begin(), a.end());
	/*for (int i = 0; i < n; i++) {
		printf("%d %d\n", a[i].first, a[i].second);
	}*/
	for (int i = 0; i < n; i++) {
		if (r < a[i].first) {
			res += r - l;
			l = a[i].first;
			r = a[i].second;
		}
		else {
			r = max(a[i].second, r);
		}
	}
	res += r - l;
	printf("%d", res);
}
