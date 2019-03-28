#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n,m, map[505][505], res1 = 0, res2= 0,res=0;

int howmany9(int a) {
	string s = to_string(a);
	int b = 0;
	for (int i = 0; i < s.length(); i++) {
//		if (s.find('9') != -1) b++;
		if (s[i] == '9') b++;
	}
	return b;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int cnt = 0, sum = 0, all = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cnt = howmany9(map[i][j]);
			if (cnt != 0) {
				sum += cnt;
				all += cnt;
			}
		}
		res1 = max(res1, sum);
		cnt = 0, sum = 0;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cnt = howmany9(map[j][i]);
			if (cnt != 0) {
				sum += cnt;
			}
		}
		res2 = max(res2, sum);
		cnt = 0, sum = 0;
	}
	res = max(res1, res2);
//	printf("%d %d", res1, res2);
	printf("%d", all-res);
}
