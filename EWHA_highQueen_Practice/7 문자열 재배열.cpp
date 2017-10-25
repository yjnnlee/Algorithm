#include <stdio.h>
#include <ctype.h>
#include <string>
char a[30], b[30], chk[10000];

int main() {
	scanf("%s%s", a, b);
	for (int i = 0; i < strlen(a); i++) {
		a[i] = tolower(a[i]);
		b[i] = tolower(b[i]);

		chk[a[i]] = a[i];
	}
	int cnt = 0;
	for (int i = 0; i < strlen(b); i++) {
		if (chk[b[i]]) cnt++;
	}

	if (cnt == strlen(a)) {
		puts("YES");
	}
	else puts("NO");
//	printf("%s", a);
}
