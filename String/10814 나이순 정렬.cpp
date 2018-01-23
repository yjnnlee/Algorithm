#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
//vector<pair<int, string>> p;

struct P {
	int age, num;
	char name[105];
};
struct P a[100005];
bool cmp(const struct P &a, const struct P &b) {
	if(a.age == b.age) return a.num < b.num;
	else return a.age < b.age;
}
int main() {
	scanf("%d", &n);
//	vector<P> p(n);
	for (int i = 0; i < n; i++) {
		scanf("%d %s", &a[i].age, a[i].name);
		a[i].num = i;
	}
	stable_sort(a, a + n, cmp);
//	stable_sort(p.begin(), p.end(), cmp);
	for (int i = 0; i < n; i++) {
		//		printf("%d %s\n", p[i].first, p[i].second);
//		cout << p[i].age << " " << p[i].name << endl;
		printf("%d %s\n", a[i].age, a[i].name);
	}
}
