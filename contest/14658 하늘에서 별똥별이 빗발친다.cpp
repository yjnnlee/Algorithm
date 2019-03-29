//#include <stdio.h>
//#include <algorithm>
//using namespace std;
//int n, m, l, k, cnt = 0, res = 0;
//pair<int, int> p[103];
//
//int star(int x, int y) {
//	for (int i = 0; i < k; i++) {
//		if (p[i].first == x && p[i].second == y) {
//			return 1;
//		}
//	}
//	return 0;
//}
//
//bool compare(const pair<int, int>&a, const pair<int, int>&b) {
//	if (a.second == b.second) return a.first < b.second;
//	return a.second < b.second;
//}
//
//int main() {
//	scanf("%d%d%d%d", &n, &m, &l, &k);
//	for (int i = 0; i < k; i++) {
//		scanf("%d%d", &p[i].first, &p[i].second);
//	}
//	sort(p, p + k,compare);
//	
//	for (int i = 0; i < k; i++) {
//		for (int y = p[i].second; y <= p[i].second + l; y++) {
//			for (int x = p[i].first; x <= p[i].first + l; x++) {
//				if (x > n || y > m || x < 0 || y < 0) continue;
//				if (star(x,y)) cnt++;
//			}
//		}
////		printf(">%d\n", cnt);
//		if (res < cnt) res = cnt;
//		cnt = 0;
//	}
//	printf("%d", k-res);
//}


#include <stdio.h>
#include <algorithm>
using namespace std;
int n, m, l, k, res = 0, cnt = 0;
pair<int, int> p[103];

void star(int x, int y) {
	for (int i = 0; i < k; i++) {
		if (p[i].first >= x && p[i].first <= x+l &&
			p[i].second >= y && p[i].second <= y+l) {
			cnt++;
		}
	}
}

int main() {
	scanf("%d%d%d%d", &n, &m, &l, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d%d", &p[i].first, &p[i].second);
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			star(p[i].first, p[j].second);
			if (res < cnt) res = cnt;
			cnt = 0;
		}
	}
	printf("%d", k - res);
}
