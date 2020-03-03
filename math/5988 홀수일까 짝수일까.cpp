#include <stdio.h>
#include <string.h>
using namespace std;
int n;
char num[100];

int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%s", &num);
		if ((num[strlen(num) - 1] - '0') % 2) { //이렇게 하면 char to int
			puts("odd");
		}
		else puts("even");
	}
}
