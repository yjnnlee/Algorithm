//#include <stdio.h>
//int n, b[300005], res = 0;
//
//bool isFirst(int max) { //가장 큰 값인가?
//	for (int i = 0; i < n; i++) {
//		if (max < b[i]) return false;
//	}
//	return true;
//	//자기 자신은 어떻게 계산? -> 어차피 false일듯
//}
//int main() {
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &b[i]);
//	}
//	for (int i = 0; i < n; i++) {
//		b[i] += n;
//		if (isFirst(b[i])) res++;
//		b[i] -= n;
//	}
//	printf("%d", res);
//} //시간초과 코드 -> for문을 두 번 돌면 터짐 & 반례있음(1 3 3 3 -> 답3)

//#include <stdio.h>
//#include <algorithm>
//using namespace std;
//
//int n, b[300005], res = 0, add = 0;
//bool cmp(const int &a, const int &b) {
//	return a > b;
//}
//int main() {
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &b[i]);
//	}
//	sort(b, b + n, cmp);
//	for (int i = 0; i < n; i++) {
//		if (b[i] + n >= add) res++;
//		add = max(add, b[i] + i + 1);
//	}
//	printf("%d", res);
//} //힌트를 보고 짰지만 직관적으로 이해가 잘 되지 않는 코드

#include <stdio.h>
#include <algorithm>
using namespace std;
int n, b[300005], res = 0, add = 0, max_score;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
	}
	sort(b + 1, b + n + 1);
	max_score = b[n] + 1;
	for (int i = n; i >= 1; i--) {
		if (b[i] + n >= max_score) {
			res++;
			max_score = max(max_score, b[i] + (n - i + 1));
		}
	}
	printf("%d", res);
	//내가 짠 코드
}

//#include <stdio.h>
//#include <algorithm>
//using namespace std;
//int n, b[300005], res = 0, add = 0, max_score = 0;
//bool cmp(const int &a, const int &b) {
//	return a > b;
//}
//int main() {
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++) {
//		scanf("%d", &b[i]);
//	}
//	sort(b + 1, b + n + 1, cmp);
//	for (int i = 1; i <= n; i++) {
//		if (b[i] + n >= max_score) res++;
//		if (max_score < b[i] + i) max_score = b[i] + i;
////		printf("%d\n", max_score);
//	}
//	printf("%d", res);
//	//다른 사람의 다른 풀이
//}
