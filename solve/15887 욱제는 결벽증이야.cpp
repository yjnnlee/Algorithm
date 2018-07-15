#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int a[3000], b[3000], n;
vector<pair<int, int>> v;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
//		scanf("%d", a+i); //5 2 1 4 3 아래랑 같은 의미임
		scanf("%d", &a[i]);
		b[a[i]] = i;		//3 2 5 4 1
	}
	for (int i = 1; i <= n; i++) {
		//if (i > b[i]) swap(i, b[i]);
		//if (i != b[i]) {
		//	reverse(a + i, a + b[i]);
		//	v.push_back({ i,b[i] });
		//	for (int j = i; j <= b[i]; j++) {
		//		b[a[j]] = j;
		//	}
		//}
		
		int x = i, y = b[i];
		if (x > y) swap(x, y);
		if (x != y) {
			reverse(a + x, a +y+1);
			v.push_back({ x,y });
			for (int j = x; j <= y; j++) {
				b[a[j]] = j;
			}
		}
	}

	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++) {
		printf("%d %d\n", v[i].first, v[i].second);
	}
}
