#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <memory.h>
using namespace std;
struct b {
	int m, v;
};
vector<b> a;

bool compare(const b& first, const b& second) {
	if (first.v == second.v) return first.m < second.m; //가격이 같으면 무게가 적은 순서대로
	else return first.v > second.v; //가격이 높은 순서대로
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

	sort(a.begin(), a.end(), compare);

	vector<int> bag;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		bag.push_back(x);
	}
	sort(bag.begin(), bag.end());


	int res = 0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			if (a[j].m <= bag[i] && a[j].m != -1 && bag[i] != -1) {
				res += a[i].v;
				bag[i] = -1;
				a[j].m = -1;
				break;
			}
		}
	}
	cout << res;
}
