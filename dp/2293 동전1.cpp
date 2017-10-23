#include <stdio.h>
#include <iostream>
#include <algorithm>
#define INF 1e9;
using namespace std;

int n, k;
int value[10001], d[10001]; //d[n]=주어진 동전들로 n원을 만드는 경우

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &value[i]);
	}

	d[0] = 1; //하나도 안써서 0원을 만드는 것도 한가지 방법
	
	for (int now = 0; now < n; now++) {
		for (int i = value[now]; i <= k; i++) {
			d[i] += d[i - value[now]];
		}
	}
	
	printf("%d\n", d[k]);
}
/*
3 15
1
5
12

맨 끝자리가 3원인 경우
최소갯수로 k-3원을 만들고 3원짜리 추가

5일 경우 10월일 경우 15원일 경우 다 해봄
d[k] = k원을 만드는데 필요한 최소 동전 갯수

다음 중 최솟값
d[k-1] +1
d[k-10] +1
d[k-15] +1

단, d[0] = 0

점화식
d[k] = min(d[k-a[i]] + 1)
*/
