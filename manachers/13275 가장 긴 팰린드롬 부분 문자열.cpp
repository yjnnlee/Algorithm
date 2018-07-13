#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int p[300002], res=0; //p는 팰린드롬의 반경을 저장
char s[200005], input[200005]; //#추가한 문자열->s

void manachers(char s[], int n) {
	int m = 0, r = 0; //m은 센터, r은 팰린드롬 구간 중 오른쪽 범위(센터+반경)
//	printf("%d", n);

	for (int i = 0; i < n; i++) {
		int mirror = 2 * m - i; //센터를 기준으로 대칭인 곳
//		printf(">%d\n", mirror);

		if (i < r) { //현재가 r보다 작으면 대칭값을 가져옴
			p[i] = min(r - i, p[mirror]); //오른쪽 끝까지 남은 범위 vs 팰린드롬을 보장하는 최소 길이
		}

		//최솟값을 구했으니까 최솟값 범위 밖~끝까지 팰린드롬이 더 있나 확인한다
		while (i > p[i] && //i가 팰린드롬 반경을 넘는다
			i + p[i] - 1 < n && //팰린드롬 전체 길이가 문장 길이보다 작아야 한다
			s[i - p[i] - 1] == s[i + p[i] + 1]) { //현재-반경-1 과 현재+반경+1이 같으면 팰린드롬 길이를 늘림
			p[i]++;
		}
		if (p[i] + i > r) { //팰린드롬이 늘어났으면
			r = p[i] + i;
			m = i;
		}
	}
}

int main() {
	scanf("%s", input);
	int inputlen = strlen(input);
	for (int i = 0; i <= inputlen * 2; i++) {
//		printf(">%c\n", input[i / 2]);
		if (i % 2) s[i] = input[i/2];
		else s[i] = '#';
	}
	//이걸 넣어주는 이유: 팰린드롬이 짝수면 가운데 수가 없어서 대칭을 할 수 없기 때문에
	//넣어도 되는 이유: 어차피 대칭하면 같음

//	printf("%s %d", s, strlen(s));
	int slen = strlen(s);
	manachers(s, slen);

	for (int i = 0; i < slen; i++) {
		int now = p[i];
		if (i % 2 == 0 && p[i] % 2 == 1) now++;
		res = max(res, now);
	}
	printf("%d", res);
	
}
