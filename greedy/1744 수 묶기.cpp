#include <stdio.h>
#include <algorithm>
using namespace std;
int n, a[10005];
long long int sum = 0;

bool compare(const int&a, const int&b) {
	//양수면 내림으로 음수면 오름차순으로(큰수가 무조건 앞으로)
	if (a > 0 && b > 0) return a > b;
	else return b > a;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n, compare);
	//for (int i = 0; i < n; i++) {
	//	printf("%d\n", a[i]);
	//}
	for (int i = 0; i < n; i++) {
		if (a[i] > 0 && a[i + 1] == 1) { //1과 양수 곱은 더하는 게 이득
			sum += a[i] + a[i + 1];
			i++;
		}
		else if (a[i] > 0 && a[i + 1] > 0 && i + 1 < n) { //양수는 큰 수끼리 곱합
			sum += a[i] * a[i + 1];
			i++;
//			printf("a");
		}
		else if (a[i] < 0 && a[i + 1] == 0 && i + 1 < n) { //0과 음수면 곱해서 0으로
			i++;
//			printf("b");
		}
		else if (a[i] == 0) continue; //0과 음수 조합이 아니면 무조건 0은 합치는 게 이득
		else if (a[i] < 0 && a[i + 1] < 0 && i + 1 < n) { //음수도 큰 수끼리 곱함
			sum += a[i] * a[i + 1];
			i++;
//			printf("c");
		}
		else { //아무것도 아니면 그냥 더함
			sum += a[i];
//			printf("d");
		}
	}
	printf("%lld", sum);
}
