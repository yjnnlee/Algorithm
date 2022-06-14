#include <iostream>
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    unsigned long long sum = 0;
    for(int i=1;i<=count;i++){
        sum+=price*i;
    }
    //cout<<sum;
    if(sum>money) answer = sum-money;
    if(answer == -1) return 0;
    else return answer;
}
