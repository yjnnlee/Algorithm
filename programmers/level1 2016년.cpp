#include <string>
#include <vector>
using namespace std;
int month[] = {31,29,31,30,31,30,31,31,30,31,30,31};
char *day[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int days=0;
string solution(int m, int d) {
    for(int i=0;i<m-1;i++){
        days+=month[i];
    }
    days+= d+4;
    return day[days%7];
}
