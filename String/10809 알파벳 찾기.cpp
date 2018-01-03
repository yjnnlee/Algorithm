#include <stdio.h>
#include <string.h>
char a[101];
int n[26];
int main(){
	scanf("%s", a);
	for (int i = 0; i < 26; i++){
		n[i] = -1;
	}

	for (int i = 0; i < strlen(a); i++){
		if (n[a[i] - 'a'] == -1){
			n[a[i] - 'a'] = i;
		}
		else continue;
	}

	for (int i = 0; i < 26; i++){
		printf("%d ", n[i]);
	}
}
