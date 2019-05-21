#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int f(int ii, int jj, char* s){
    int answer = 0;
//    printf("%d ", ((jj+1)-(ii+1)+1));
    while(1){
        if(((jj+1)-(ii+1)+1)%2 == 1){ //홀수면 만날 수 있다
            if(ii == jj) return answer+1; //만나면 팰린드롬
            if(s[ii++] == s[jj--]) answer+=2;
            else return -1; //틀리면 팰린드롬이 아님
        }
        else { //짝수면 교차된다
            if(ii > jj) return answer;
            if(s[ii++] == s[jj--]) answer+=2;
            else return -1; //틀리면 팰린드롬이 아님
        }
    }
}
int solution(char* s) {
    int answer = 1, answer2; //하나만 있으면 1, abc처럼 하나도 없으면 1
    int len = strlen(s);
    for(int i=0;i<len;i++){
        for(int j=len-1;j>i;j--){
            if(s[i] == s[j]){
                int answer2 = f(i,j,s);
//                printf("%d ", answer2);
                if(answer2> answer) answer = answer2;
            }
        }
    }
    return answer;
}

/*
처음이 팰린드롬
중간에 팰린드롬
끝에 팰린드롬
처음 문자가 뒤에도 중복해서 나온 경우 abcabba
a하나만 있어도 팰린드롬 1
abc만 있으면 팰린드롬 1
abba 처럼 짝수인 경우
aa처럼 연속으로 나온 경우 짝수
aaa처럼 연속 홀수
*/
