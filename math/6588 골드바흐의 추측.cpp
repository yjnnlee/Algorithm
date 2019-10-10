#include <iostream>
using namespace std;
#define size 1000003
int a[size], sosu[size], index = 0;
bool chk = false;

int main() {
	for(int i=2;i*i<=size;i++){
		if(!a[i]){
			for(int j=i*i;j<=size;j+=i){
				a[j] = 1;
			}
		}
	}
	a[1] = 1;
	
/*	for(int i=3;i<=100001;i++){ //소수를 저장
		if(a[i] != 0) sosu[index++] = a[i];
	}*/
	
	int tmp;
	while(1){
		scanf("%d", &tmp);
		if(tmp == 0) break;
		chk = false;

		for(int i =3;i<=tmp;i+=2){
			if(!a[i] && !a[tmp-i]){
				printf("%d = %d + %d\n", tmp, i, tmp-i);
				chk = true;
				break;
			}
		}
		if(!chk) printf("Goldbach's conjecture is wrong.\n"); //개행문자 조심;
	}
}
