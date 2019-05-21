#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    char *a[2] = {"수", "박"};
    for(int i = 0;i<n;i++){
        answer += a[i%2];
    }
    return answer;
}
