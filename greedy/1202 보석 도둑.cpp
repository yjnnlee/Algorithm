#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
int n, k, c[300005];
long long int sum = 0;
struct j {
	int m;
	int v;
}a[300005];
priority_queue<int> pq;
/*
bool cmp1(pair<int, int> a, pair<int, int> b){
	return a.first<b.first;
}

bool rcmp2(pair<int, int> a, pair<int, int> b){
	return a.second>b.second;
}

bool cmp(jew a, jew b) { //내림차순
	if (a.v != b.v)
		return a.v > b.v;
	else
		return a.m < b.m;
}

sort(a, a+n,  [](J a, J b) { return a.price > b.price; });
*/
bool compare(const j&x, const j&y) {
	return x.m < y.m;
}

//bool compare2(const int&x, const int&y) {
//	return x > y;
//}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].m, &a[i].v);
	}
	for (int i = 0; i < k; i++) {
		scanf("%d", &c[i]);
	}

	sort(a, a + n, compare);
	sort(c, c + k);

	for (int i = 0, j = 0; i < k; i++) {
		/*반복을 돌면서 c[i]값보다 작은 무게의 모든 가중치를 저장
		그 가중치들 중에 가장 높은 값을 저장
		가장 높은 값으로 정렬해주는건 prioority_queue가 해줌
		*/
		while (j < n && a[j].m <= c[i]) {
			pq.push(a[j++].v);
		}
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}
	printf("%lld", sum);
}
