#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int n, t;

typedef pair<int, int> p;
vector<p> a;
vector<int> d;
int f(int x) {
	return lower_bound(d.begin(), d.end(), x) - d.begin();
}

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		a.push_back({ t,i }); //make_pair랑 같은거 첨알음
		d.push_back(t);
	}

	sort(d.begin(), d.end());
	d.erase(unique(d.begin(), d.end()), d.end());

	for (int i = 0; i < a.size(); i++) {
		int x = lower_bound(d.begin(), d.end(), a[i].first) - d.begin();
		printf("%d ", x + 1);
	}
}

/*http://www.koistudy.net/?mid=prob_page&NO=1812 */
