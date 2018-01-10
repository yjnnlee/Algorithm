#include <stdio.h>
#include <string.h>

char a[1001], n[1001];
int idx = 0;
int chk = 0, chk2 = 0;

int main(){
	scanf("%s", a);
	int len = strlen(a);

	bool is = true;
	for (int i = 0; i < len; i++){
		if (is){
			if (a[i] >= 'a' && a[i] <= 'z'){ //전부 소문자면 그냥 출력
				for (int j = 0; j < len; j++){
					if (!(a[j] >= 'a' && a[j] <= 'z')){
						is = false;
					}
				}
				if (is) {
					printf("%s", a);
					return 0;
				}
			}
		}
	}

	if (a[0] == '_' || a[len - 1] == '_' || (a[0] >= 'A' && a[0] <= 'Z')){
		printf("Error!");
		return 0;
	}
	else{
		for (int i = 0; i < len; i++){
			if (a[i] == '_') {
				chk = 1; //c++ 형식
				if (chk2 == 4){
					printf("Error!");
					return 0;
				}
				chk2 = 3;
				if (a[i + 1] == '_'){
					printf("Error!");
					return 0;
				}
			}
			else if (a[i] >= 'A' && a[i] <= 'Z'){
				chk = 2; //자바 형식
				if (chk2 == 3){
					printf("Error!");
					return 0;
				}
				chk2 = 4;
			}
		}
	}

	if (chk == 1){
		for (int i = 0; i < len; i++){
			if (a[i] == '_'){
				i++;
				n[idx++] = a[i] - 'a' + 'A';
			}
			else n[idx++] = a[i];
		}
	}
	else if(chk == 2){
		for (int i = 0; i < len; i++){
			if (a[i] >= 'A' && a[i] <= 'Z'){
				n[idx++] = '_';
				n[idx++] = a[i] - 'A' + 'a';
			}
			else n[idx++] = a[i];
		}
	}

	printf("%s", n);
}
