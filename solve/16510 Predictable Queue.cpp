#include <stdio.h>
#include <algorithm>
using namespace std;
int n, m, q[200001], t;

int main(){
	scanf("%d %d", &n, &m);
	int tmp, sum = 0;
	for(int i=0;i<n;i++){
		scanf("%d", &tmp);
		sum += tmp;
		q[i] = sum;
	}
	for(int i=0;i<m;i++){
		scanf("%d", &t);
		printf("%d\n", upper_bound(q,q+n,t)-q);
	}
}
