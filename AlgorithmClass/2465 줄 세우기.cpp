#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;

/*
int sum(vector<int> &tree, int i) {
	int ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= i & -i;
	}
	return ans;
}*/

/*void update(vector<int> &tree, int i, int num) {
	while (i <= num) {
		tree[i] += num;
		i += i &= i;
	}
}*/

int range(int a) {
	int tmp = 1;
	while (tmp < n) {
		tmp *= 2;
	}
	return tmp;
}

int main() {
//	scanf("%d", &n);
	cin >> n;
	int length = range(n);
	vector<int> height(n), tree(length);
	int s[100000], res[100000];

	for (int i = 0; i < n; i++) {
		cin >> height[i];
//		update(tree, height[i], 1);
//		scanf("%d", &height[i]);
//		tree[height[i]] = 1;
	}

	for (int i = 0; i < n; i++) {
		cin >> s[i];
//		scanf("%d", &s[i]);
	}

	sort(height.begin(), height.end());

	for (int i = n - 1; i >= 0; i--) {
		res[i] = height[s[i]];

		height.erase(height.begin()+s[i]);
	}

	for (int i = 0; i < n;i++) {
		printf("%d\n", res[i]);
	}
}