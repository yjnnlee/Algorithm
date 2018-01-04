#include <stdio.h>
#include <string.h>
char a[10000001];
int n[26];
bool is = true;
int main(){
	scanf("%s", a);
	int len = strlen(a);
	for (int i = 0; i < len; i++){
		if (a[i] >= 'A' && a[i] <= 'Z') n[a[i] - 'A']++;
		if (a[i] >= 'a' && a[i] <= 'z') n[a[i] - 'a']++;
	}

	int max = 0, maxd = 0;
	for (int i = 0; i < 26; i++){
		if (n[i] > max) {
			max = n[i];
			maxd = i;
			is = false;
		}
		else if (max == n[i]) is = true;
	}

	if (is) printf("?\n");
	else printf("%c\n", maxd + 'A'); 
}
