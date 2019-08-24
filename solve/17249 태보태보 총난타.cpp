#include <stdio.h>
#include <string.h>
char a[1005];
int cnt = 0;
 
int main(void) {
	scanf("%s", a);
	for(int i=0;i<strlen(a);i++){
		if(a[i] == '@') cnt++;
		else if(a[i] == '(') {
			printf("%d ", cnt);
			cnt = 0;
		}
	}
	printf("%d", cnt);
}
