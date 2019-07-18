#include <stdio.h>
#define MOD 1000000000
int num, dp[105][10][1<<10];
//int chk[10] = {0,1,2,3,4,5,6,7,8,9};
long long res = 0;

int f(int n, int now, int chk){
    if(dp[n][now][chk]) return dp[n][now][chk];
//    chk[now] = -1;
    if(n==1) {
//        for(int k=0;k<=9;k++){
//            if(chk[k] != -1) return 0;
//        }
        if(chk==(1<<10)-1) return 1; //전부 1이면
        else return 0;
    }

    if(now == 0) { 
        return dp[n][now][chk] = f(n-1,1,chk|1<<(now+1))%MOD;
//        chk[now] = now;
    }
    else if(now == 9) {
        return dp[n][now][chk] = f(n-1,8,chk|1<<(now-1))%MOD;
//        chk[now] = now;
    }
    else {
        return dp[n][now][chk] = (f(n-1, now+1,chk|1<<(now+1))+f(n-1,now-1,chk|1<<(now-1)))%MOD;
//        chk[now] = now;
    }
}

int main() {
    scanf("%d", &num);

    for(int i=1;i<=9;i++){
        res += (f(num, i,1<<i)%MOD); //자리수, 현재 숫자
    }
    printf("%lld", res%MOD);
}
