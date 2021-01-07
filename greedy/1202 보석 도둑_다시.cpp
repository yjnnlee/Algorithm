#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <memory.h>
#include <set>
using namespace std;
struct b {
	int m, v;
};
vector<b> a;

bool compare(const b& first, const b& second) {
	if (first.v == second.v) return first.m < second.m; //가격이 같으면 무게가 적은 순서대로
	else return first.v > second.v; //가격이 높은 순서대로(내림차순)
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a.push_back({ x, y });
	}

//	sort(a.begin(), a.end(), compare); 이렇게도 되지만
	sort(a.begin(), a.end(), [](b u, b v) {
		return u.v > v.v;
	}); //이렇게도 된다

	multiset<int> bag;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		bag.insert(x);
	}

	long long res = 0;
	for (int i = 0; i < n; i++) {
		auto it = bag.lower_bound(a[i].m); //가방 무게 x보다 큰 보석 중에 가장 작은 수를 찾는다
		if (it != bag.end()) { //결과가 있다면
			res += a[i].v;
			bag.erase(it);
		}
	}
	cout << res;
}
