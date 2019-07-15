#include <stdio.h>
int need, have, res = 0, res2 = 0, res3 = 0, n;
char name[75][25];

int main() {
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%s%d%d", name[i],&need,&have);
		int tmp = 0, restmp = 0;
		while(have > 0){
			tmp = have/need;
			if(tmp == 0) break;
			have -= need*tmp;
			have+=2*tmp;
			restmp+=tmp;
		}
		
		if(restmp > res2) {
			res2 = restmp;
			res3 = i;
		}
		res += restmp;
	}
	printf("%d\n%s",res,name[res3]);
}
