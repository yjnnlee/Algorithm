#include <stdio.h>
#include <stack>
using namespace std;

int n;
long long int a[1000006], res = 0;
stack<int> s;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}

	for (int i = 0; i < n; i++) {
		while (!s.empty() && a[s.top()] > a[i]) {
			int h = a[s.top()];
			s.pop();
			int w = i;
			if (!s.empty()) w = i - s.top() - 1;

			if (res < w*h) res = (long long)w*h;
		}
		s.push(i);
	}

	while (!s.empty()) {
		int h = a[s.top()];
		s.pop();
		int w = n;
		if (!s.empty()) w = n - s.top() - 1;

		if (res < w*h) res = (long long)w*h;
	}

	printf("%lld", res);
}
