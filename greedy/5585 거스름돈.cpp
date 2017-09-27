#include <stdio.h>
int coin[] = {500, 100, 50, 10, 5, 1}, n; //물건값
int res = 0, nowCoin = 0, nowMoney = 0; //가진돈

int main(){
	scanf("%d", &n);
	n = 1000-n;
	int price = n;

	while(nowMoney<n){
		if(coin[nowCoin] <= price){
			nowMoney+=coin[nowCoin];
			price -= coin[nowCoin];
			res++;

		}
		else nowCoin++;
	}

	printf("%d", res);
}
