#include <string>
#include <vector>
#include <math.h>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long num = (long long)sqrt(n);
    if(num*num == n){
        answer = (num+1)*(num+1);
    }
    else answer = -1;
    return answer;
}   
