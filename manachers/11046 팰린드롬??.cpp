
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int res=0, n, m, start, endd; //p는 팰린드롬의 반경을 저장
char s[200005], input[200005]; //#추가한 문자열->s
vector<int> x, y;

vector<int> manachers(vector<int> &s, int n) { 
	vector<int> p(n + 1, 0);
	int m = 0, r = 0;
//	printf("%d\n", n);
	for (int i = 1; i <= n; i++) { // 0~10
		int mirror = m * 2 - i;
//		printf(">mirror%d m%d r%d %C %C\n", mirror, m, r, input[i-p[i]-1], input[i+p[i]+1]);
		if (i <= r) {
			p[i] = min(r-i, p[mirror]); //r-i는 팰린드롬 오른쪽 끝 - 현재 위치
		}

		while (i > p[i] + 1 && i + p[i] + 1 <= n && s[i - p[i] - 1] == s[i + p[i] + 1]){
			p[i]++;
		}

		if (p[i] + i > r) {
			m = i;
			r = p[i] + i;
		}

		//for (int i = 0; i < 5; i++) {
		//	printf("%d ", p[i]);
		//}
		//printf("\n\n");
	}
	return p;
}

//bool ispal(int ss, int ee) { // 0 2
////	printf(">>%d %d\n", input[ss], input[ee]);
//	if (ss == ee) return true;
//
//	int mm = (ss + ee) / 2;
////	printf(">%d\n", mm);
//	if (p[mm]) { //팰린드롬이면
//		printf(">%d %d\n", 1 + p[mm] * 2, (ee + 1) - (ss + 1) + 1);
//		if (1 + p[mm] * 2 == (ee + 1) - (ss + 1) + 1) {
////			printf("EE");
//			return true;
//		}
//		else return false;
//	}
//	else return false;
//}

int main() {
	scanf("%d", &n);
	x.assign(n + 1, 0);
	y.assign(n * 2 + 2, 0);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x[i]);
		y[i * 2] = x[i];
	}

	vector<int> a = manachers(x, n);
	vector<int> b = manachers(y, n*2+1);

	scanf("%d", &m);
	while (m--) {
		scanf("%d %d", &start, &endd);
		if ((endd - start) % 2) {
			int mid = (endd - start + 2);
			printf("%d\n", b[mid] / 2 >= (endd - start) / 2 + 1 ? 1 : 0);
		}
		else {
			int mid = (endd + start) / 2;
			printf("%d\n", a[mid] >= (endd - start) / 2 ? 1 : 0);
		}
	}
	
}

