#include <string>
#include <iostream>
using namespace std;
char a[4] = {'U', 'C', 'P', 'C'};
string str;
int index = 0;
int main() {
    getline(cin, str);

    for (auto &i : str) {
        if (idx == 4) break;
        else if (i == al[idx]) idx++;
    }
    if (idx == 4) cout << "I love UCPC";
    else cout << "I hate UCPC";
}
 
