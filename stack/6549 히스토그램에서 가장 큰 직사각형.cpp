#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;
stack<int> s;
int n;
long long int stick[100005];
long long int res = 0, w, h;

int main() {
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;

		for (int i = 0; i < n + 2; i++) stick[i] = 0;
		for (int i = 0; i < n; i++) {
			scanf("%lld", &stick[i]);
		}

		for (int i = 0; i < n; i++) {
			while (!s.empty() && stick[s.top()] > stick[i]){
				h = stick[s.top()];
				s.pop();
				
				if (!s.empty()) w = i - s.top() - 1;
				else w = i;

				if (res < w * h) res = (long long)w*h;
//				printf("%d %d %d\n", w, h, w*h);
			}
			s.push(i);
		}
		while (!s.empty()) {
			h = stick[s.top()];
			s.pop();

			if (!s.empty()) w = n - s.top() - 1;
			else w = n;

			if (res < w*h) res = (long long)w*h;
			//printf(">%d %d %d\n", w, h, w*h);
		}

		printf("%lld\n", res);
		res = 0, w = 0, h = 0;
	}
}
