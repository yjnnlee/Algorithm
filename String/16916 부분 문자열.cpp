#include <iostream>
#include <vector>
#include <string.h> //strstr
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s, p;
	cin >> s >> p;
	char* ptr = strstr((char*)s.c_str(), (char*)p.c_str()); //c_str: c++ string을 c문자열로
	if (ptr != NULL) cout << 1;
	else cout << 0;
}
