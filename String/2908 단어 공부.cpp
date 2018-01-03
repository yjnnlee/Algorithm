#include <stdio.h>
#include <string.h>
char a[4], b[4];
int max = 0;
bool is = false;
int main(){
	scanf("%s %s", a, b);

	for (int i = 2; i >= 0; i--){
		if (a[i] > b[i]) {
			is = true;
			break;
		}
		else if (a[i] < b[i]){
			break;
		}
	}
	if (is) {
		for (int i = 2; i >= 0; i--){
			printf("%c", a[i]);
		}
	}
	else{
		for (int i = 2; i >= 0; i--){
			printf("%c", b[i]);
		}
	}
}
