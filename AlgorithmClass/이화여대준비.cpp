//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//string n;
//vector<int> phone;
//
//int main() {
//	cin >> n;
//
//	for (int i = 0; i < n.size(); i++) {
//		if (n[i] >= '0' && n[i] <= '9') {
//			cout << n[i];
//		}
//	}
//}

//#include <iostream>
//using namespace std;
//int a, b, res = 0, max;
//
//int gcd(int a, int b) {
//	if (b == 0) {
//		return a;
//	}
//	gcd(b, a%b);
//}//최대공약수
//
//int lcm(int a, int b) {
//	return (a*b) / gcd(a, b);
//}//최소공배수
//
//int main() {
//	cin >> a >> b;
//
//	cout << gcd(a, b);
//}

//피보나치
//#include <iostream>
//using namespace std;
//int n;
//int f(int n) {
//	if (n == 1 || n == 0) return n;
//	else return f(n - 1) + f(n - 2);
//}
//
//int main() {
//	cin >> n;
//	for (int i = 0; i < n;i++) {
//		cout << f(i) << " ";
//	}
//}

