#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int a[10000], b[10000], c[10000];
    int p[] = {1,2,3,4,5}, q[] = {2,1,2,3,2,4,2,5}, k[] = {3,3,1,1,2,2,4,4,5,5};
    int len = answers.size(), maxn = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for(int i=0;i<len;i++){
        a[i] = p[i%5];
    }
    for(int i=0;i<len;i++){
        b[i] = q[i%8];
    }
    for(int i=0;i<len;i++){
        c[i] = k[i%10];
    }

    for(int i=0;i<len;i++){
        if(a[i] == answers[i]) cnt1++;
    }
    for(int i=0;i<len;i++){
        if(b[i] == answers[i]) cnt2++;
    }
    for(int i=0;i<len;i++){
        if(c[i] == answers[i]) cnt3++;
    }
    if(cnt1 == cnt2 && cnt2 == cnt3) {
        answer.push_back(1);
        answer.push_back(2);
        answer.push_back(3);
    }
    else if(cnt1 == cnt2 && cnt1 != 0){
        answer.push_back(1);
        answer.push_back(2);
    }
    else if(cnt2 == cnt3 && cnt2 != 0){
        answer.push_back(2);
        answer.push_back(3);
    }
    else if(cnt1 == cnt3 && cnt3 != 0){
        answer.push_back(1);
        answer.push_back(3);
    }
    else{
        maxn = max(cnt1, max(cnt2, cnt3));
        if(maxn == cnt1) answer.push_back(1);
        if(maxn == cnt2) answer.push_back(2);
        if(maxn == cnt3) answer.push_back(3);
    }
    
    return answer;
}
