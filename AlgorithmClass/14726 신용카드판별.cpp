//#include <stdio.h>
//#include <vector>
//using namespace std;
//int n;
//char a[20], res[1003];
//
////void print() {
////	printf("%s", a);
////	printf("\n");
////}
//
//int main() {
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		scanf("%s", &a);
//
//
//		for (int j = 16; j > 0; j -= 2) {
//			int sum = 0, tmp = a[j] - '0';
//			if (a[j] * 2 >= 10) {
//				a[j] = tmp * 2 / 10 + tmp * 2 % 10;
//			}
//			else a[j] = tmp;
//
//			for (int i = 0; i < 16; i++) {
//				sum += a[i]-'0';
//			}
//			//printf("tmp: %d\n", tmp);
//
//			if (sum % 10 == 0) {
//				res[i] = 'T';
//			}
//			else res[i] = 'F';
//		}
//		//print();
//
//	}
//
//	for (int i = 0; i < n; i++) {
//		printf("%c\n", res[i]);
//	}
//}
