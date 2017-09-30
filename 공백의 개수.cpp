#include <iostream>
using namespace std;
char a[100];
int res = 0;
int main() {
	cin.getline(a, sizeof(a));
	int i = 0;
	while(a[i]!=NULL) {
		if (a[i] == ' ') {
			res++;
		}
		i++;
	}
	cout << res;
}
