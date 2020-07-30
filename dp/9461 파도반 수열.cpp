#include <iostream>
int main() { 
    long long P[100] = { 0,1, 1, 1, 2, 2, 3, 4, 5, 7, 9 };
    for (long long idx = 11; idx <= 100; idx++)
        P[idx] = P[idx - 1] + P[idx - 5];
    int T;  scanf("%d", &T);
    while (T--){
        int sub; scanf("%d", &sub);
        printf("%lld\n", P[sub]);
    }
}
