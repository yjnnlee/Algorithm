#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int p[300002], res=0; //p는 팰린드롬의 반경을 저장
char s[200005], input[200005]; //#추가한 문자열->s
int tmp;
void manachers(char s[], int n) {
	int m = 0, r = 0;
	
	for (int i = 0; i < n; i++) {
		int mirror = m * 2 - i;

		if (i < r) {
			p[i] = min(r-i, p[mirror]); //r-i는 팰린드롬 오른쪽 끝 - 현재 위치
		}
		while (i > p[i] && i + p[i] - 1 < n && s[i - p[i] - 1] == s[i + p[i] + 1]){
			p[i]++;
		}

		if (p[i] + i > r) {
			m = i;
			r = p[i] + i;
		}
	}
	tmp = m;
}
int main() {
	scanf("%s", input);
	int inputlen = strlen(input);
	for (int i = 0; i <= inputlen * 2; i++) {
		if (i % 2) s[i] = input[i / 2];
		else s[i] = '#';
	}

	int slen = strlen(s);
	manachers(s, slen);

	for (int i = 0; i < slen; i++) {
		int now = p[i];
		if (i % 2 == 0 && p[i] % 2 == 1) now++;
		res = max(res, now);
	}
	printf("%d", res);
//	printf("\n%c", s[tmp]);
}
