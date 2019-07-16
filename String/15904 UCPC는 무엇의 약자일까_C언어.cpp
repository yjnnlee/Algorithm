#include <stdio.h>
#include <string.h>
char a[1005];
int chk[4];
int main() {
	scanf("%[^\n]s", a);
	int len = strlen(a);
	for(int i=0;i<len;i++){
		if(a[i]=='U') chk[0] = 1;
		if(a[i]=='C'){
			if(chk[0]) chk[1] = 1;
			if(chk[2]) chk[3] = 1;
		}
		if(a[i]=='P') if(chk[1]) chk[2] = 1;
	}
	if(chk[3]) printf("I love UCPC");
	else printf("I hate UCPC");
}
