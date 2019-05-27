#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<string> a, b;

int bin(string x) {
	int l = 0, r = a.size() - 1, p;
	while (l <= r) {
		p = (l + r) / 2;
		if (!a[p].compare(x)) return 1; //문자열 비교는 compare
		else if (a[p] < x) l = p + 1;
		else r = p - 1;
	}
	return 0;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		a.push_back(name);
	}
	sort(a.begin(), a.end()); //이진탐색을 위한 소팅 잊지말기
	for (int i = 0; i < m; i++) {
		string name;
		cin >> name;

		if(bin(name)) b.push_back(name);
	}
	printf("%d\n", b.size());
	sort(b.begin(), b.end());
	for (int i = 0; i < b.size(); i++) {
		cout << b[i] << endl;
	}
}


//int n, m; //시간초과
//vector<string> a, b;
//int main() {
//	scanf("%d %d", &n, &m);
//	for (int i = 0; i < n; i++) {
//		string name;
//		cin >> name;
//		a.push_back(name);
//	}
//	for (int i = 0; i < m; i++) {
//		string name;
//		cin >> name;
//		b.push_back(name);
//	}
//	printf("%d\n", b.size());
//	for (int i = 0; i < b.size(); i++) {
//		if (find(a.begin(), a.end(), b[i]) != a.end()) {
//			cout << b[i] << endl;
//		}
//	}
//}
