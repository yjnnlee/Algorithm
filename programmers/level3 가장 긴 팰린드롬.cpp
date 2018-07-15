#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
int p[100000];
int min(int a, int b){
    if(a<b) return a;
    else return b;
}
int max(int a, int b){
    if(a<b) return b;
    else return a;
}
int solution(char* ss) {
    int len2 = strlen(ss);
    char s[6000];
    for(int i=0;i<=len2*2;i++){
        if(i%2) s[i] = ss[i/2];
        else s[i] = '#';
    }
    int m=0,r=0;
    int len = strlen(s);
    for(int i=0;i<len;i++){
        int mirror = m * 2 -i;
        
        if(r>i){
            p[i] = min(r-i, p[mirror]);
        }
        
        while(i>p[i] && i+p[i]-1<len && s[i-p[i]-1] == s[i+p[i]+1]) p[i]++;
        if(p[i]+i > r){
            m = i;
            r = p[i] + i;
        }
    }
    int res = 0;
    for(int i=0;i<len;i++){
        int now = p[i];
        if(p[i] % 2 == 1 && i%2==0) now++;
        res = max(res, now);
    }
    return res;
}
