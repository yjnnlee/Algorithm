#include <stdio.h>
#include <string.h>
char a[10000001];
int n[26];
int main(){
	scanf("%[^\n]s", a);
	int len = strlen(a);
	for (int i = 0; i < len; i++){
		if (a[i] >= 'A' && a[i] <= 'Z'){
			printf("%c", a[i]);
		}
	}
}
