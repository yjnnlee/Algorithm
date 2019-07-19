#include <stdio.h>
#include <algorithm>
int a,b,c;
int main(){
	scanf("%d %d %d", &a, &b, &c);
	while(c--){
		if(a<b) a++;
		else b++;
	}
	printf("%d", std::min(a,b)*2);
}
