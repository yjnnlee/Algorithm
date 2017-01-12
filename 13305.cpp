#include <stdio.h>
#include <vector>
using namespace std;

long long int n, m[10000000], p[10000000], res = 0;

int main() {
	scanf("%lld", &n);
	for (int i = 0; i < n - 1; i++) {
		scanf("%lld", &m[i]); //거리
	}
	for (int i = 0; i < n; i++) {
		scanf("%lld", &p[i]); //가격
	}

/*
2 3 1
5 2 4 1
*/
	int a = p[0];
	for (int i = 0; i < n; i++) {
		if (a > p[i]) {
			a = p[i];
		}
		res += m[i] * a;
	}

	printf("%lld", res);
}
//처음엔 무조건 사고, 자기보다 적은 가격이 나오기 전까지 길이만큼의 연료를 산다.