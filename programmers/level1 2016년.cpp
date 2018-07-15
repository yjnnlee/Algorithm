#include <string>
#include <vector>
using namespace std;
int month[] = {31,29,31,30,31,30,31,31,30,31,30,31};
char *day[] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE","WED" };

string solution(int a, int b) {
    for(int i=0;i<a-1;i++){
        b+=month[i];
    }
    return day[b%7];
}
