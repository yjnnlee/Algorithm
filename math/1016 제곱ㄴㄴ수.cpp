#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

unsigned long long int min, max;
int psSize = 0, prime[2000005], res = 0; //제곱수의 개수
vector<unsigned long long int> primeSquare;

int main() {
	scanf("%llu%llu", &min, &max);
	int temp = sqrtl((long double)max);

	prime[1] = prime[2] = 1; //sqrt(max)보다 작은 소수들의 제곱을 구할꺼임
	for (unsigned long long int i = 3; i <= temp; i++) { //제곱이 되는 수를 체크
		if (prime[i]) continue;
		for (unsigned long long int j = i*2; j <= temp; j += i) {
			if (prime[j]) continue;
			else prime[j] = 1;
		}
		primeSquare.push_back(i*i);
		psSize++;
	} 
	for (int i = 1; i < temp; i++) {
		printf("%d ", prime[i]);
	}
	//for (int i = min; i <= max; i++) {

	//}
	//printf("%d", max - min + 1 - res);
}

/*
1016번 문제 풀다가 막힘
https://www.acmicpc.net/board/view/11036
*/
