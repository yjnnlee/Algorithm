#include <stdio.h>
#include <stack>
using namespace std;
stack<int> s;
int n, stick[100005], left = 0, right = 0, h = 0, w, res = 0, area[100005], area2 = 0;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &stick[i]);
	}
	for (int i = 0; i < n; i++) {
		//스택 가장 위에 있는 막대보다 높이가 작은 막대를 만나면
		while (!s.empty() && stick[s.top()] > stick[i]) {

			//right = i - 1;
			//if (s.empty()) left = 0;
			//else left = s.top();
			h = stick[s.top()];
			s.pop();
			w = i;
			if (!s.empty()) w = i - s.top() - 1;

			//			area[h] = (right - left + 1) * stick[h];
//			if (res < area[h]) res = area[h];				

			//area2 = (right - left + 1) *stick[h];
			//if (res < area2) res = area2;
			//printf("r %d, l %d, h %d, area %d\n", right, left, stick[h], area2);
			if (res < w*h) res = w*h;
//			printf("w %d h %d wh %d\n", w, h, w*h);
		}
		s.push(i); 	//스택에는 막대의 번호가 들어감
	}
	//right가 가장 오른쪽 끝인 경우(n-1)에는 추가 처리
	while (!s.empty()) {
		//right = n - 1;
		//if (s.empty()) left = 0;
		//else left = s.top();
		h = stick[s.top()];
		s.pop();
		w = n;
		if (!s.empty()) w = n - s.top() - 1;
		if (res < w*h) res = w*h;
//		printf("w %d h %d wh %d\n", w, h, w*h);

		//area2 = (right - left + 1) * stick[h];
		//if (res < area2) res = area2;
		//printf("> r %d, l %d, h %d, area %d\n", right, left, stick[h], area2);
	}
	printf("%d", res);
}
