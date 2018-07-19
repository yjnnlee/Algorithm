#include <stdio.h>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;

pair<int, int> p;
map<int, int> m;
int t, n;

int main() {
	scanf("%d %d", &t, &n);
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d %d", p.first, p.second);
			if (p.first == 1 || p.second == 1) {
				m.insert(pair<int, int>(p.first, p.second));
			}
		}
		

	}
}