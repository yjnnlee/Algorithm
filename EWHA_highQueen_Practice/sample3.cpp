#include <stdio.h>
#include <string.h>
char what[3][30];
long long int res = 0;
char *color[11] = { "black", "brown", "red", "orange","yellow","green","blue","violet","grey","white" };

int main() {
	scanf("%s %s %s",what[0],what[1],what[2]);

	for (int j = 0; j < 10; j++) {
		if (!strcmp(what[0], color[j])) {
			res += j * 10;
		}
		if (!strcmp(what[1], color[j])) {
			res += j;
		}
	}
	for (int j = 0; j < 10; j++) {
		if (!strcmp(what[2], color[j])) {
			for (int i = 0; i < j; i++) {
				res *= 10;
			}
		}
	}

	printf("%lld", res);

}
