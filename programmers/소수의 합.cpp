#include <vector>
using namespace std;
int a[10000001];
long long solution(int N) {
    long long answer = 0;
    for(int i=2; i<=N;i++){
        a[i] = i;
    }
    for(int i=2;i*i<=N;i++){
        if(a[i]){
            for(int j=i*2;j<=N;j+=i){
                a[j] = 0;
            }
        }
    }
    for(int i=2;i<=N;i++){
        if(a[i] != 0) answer+=a[i];
    }
    return answer;
}
