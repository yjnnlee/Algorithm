#include <stdio.h>

int n, a[5000001], b[5000001];
int tree[5000001]; //펜윅트리 계산한 배열
int chk[5000001]; //일련번호의 값이 2번째 배열에 나오는 순서 미리 저장

int sum(int *tree, int i) { 
	//합구하기, 13을 이진수로 나타내면 1101이고 합은 마지막 1을 빼가면서 더한 값
	int res = 0;
	while (i > 0) {
		res += tree[i];
		i -= (i & -i); //맨 뒤에 나오는 1을 없앰
	}
	return res;
}

void update(int *tree, int i, int num, int size) {
	while (i <= size) {
		tree[i] += num;
		i += (i & -i); //맨 뒤에 나오는 1을 살린 그곳에 자기를 더함
		//와대박 ~i가 i 반전이고 -i는 ~i+1임
	}
}

int main() {
	long long int res = 0;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		chk[a[i]] = i; //a기준 b에 같은 수가 있는 순서 저장
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		res += (long long)sum(tree, n) - (long long)sum(tree, chk[b[i]]);
		update(tree, chk[b[i]], 1, n); //자기보다 큰 값이 앞에서 나온적이 있는지 계산->tree배열
	}
	printf("%lld", res);
}
