////#include <iostream>
////using namespace std;
////
////int a, b, price[10000], sum = 0, dp[10000];
////
////int main() {
////	cin >> a >> b;
////	for (int i = 0; i < a; i++) {
////		cin >> price[i];
////	}
////	dp[0] = 1;
////
////	while (tmp > 0) {
////		if (price[now] <= b) {
////			sum++;
////			tmp -= price[now];
////		}
////		else now++;
////	}
////
////	cout << sum;
////}
//
////#include <iostream>
////#include <string>
////using namespace std;
////string a;
////int res = 0;
////
////int main() {
////	getline(cin, a);
////	if (a.length() == 0) {
////		cout << 0; 
////		return 0;
////	}
////
////	for (int i = 0; i < a.length(); i++) {
////		if (a.at(i) == ' ') {
////			res++;
////		}
////	}
////	if (a.at(0) == ' ') res--;
////	if (a.at(a.length() - 1) == ' ') res--;
////
////	cout << res + 1;
////}
//
//#include <iostream>
//#include <string>
//#include <atlstr.h>
//using namespace std;
//string a;
//int res = 0;
//CString b;
//
//int main() {
//	getline(cin, a);
//
//
//	a.replace(a.begin(),a.end(), "-", "");
//
//	cout << a;
//}