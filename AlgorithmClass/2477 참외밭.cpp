//#include <stdio.h>
//int k, direction[10], length[10];
//long long int area;
//int a[10], b[10], a2[10], b2[10];
//
//int biggest(int a, int b, int c) {
//	if (a > b && a> c) {
//	}
//	else if (b > c) {
//		return b;
//	}
//	else return c;
//}
//
//int smallest(int a, int b, int c) {
//	if (a < b && a< c) {
//		return a;
//	}
//	else if (b<c) {
//		return b;
//	}
//	else return c;
//}
//
//int main() {
//	scanf("%d", &k);
//	for (int i = 0; i < 6; i++) {
//		scanf("%d %d", &direction[i], &length[i]);
//	}
//
//	for (int i = 0; i < 6; i++) {
//		if (direction[i] == 1 || direction[i] == 2) {
//			a[i] = length[i];
//		}
//		else if (direction[i] == 3 || direction[i] == 4) {
//			b[i] = length[i];
//		}
//	}
//
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 6; j++) {
//			if (a[j] != 0) {
//				a2[i] = a[j];
//				a[j] = 0;
//				break;
//			}
//		}
//	}
//	
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 6; j++) {
//			if (b[j] != 0) {
//				b2[i] = b[j];
//				b[j] = 0;
//				break;
//			}
//		}
//	}
//
//	int bigA = biggest(a2[0], a2[1], a2[2]);
//	int smallA = smallest(a2[0], a2[1], a2[2]);
//	int bigB = biggest(b2[0], b2[1], b2[2]);
//	int smallB = smallest(b2[0], b2[1], b2[2]);
//
//	printf("%d %d %d %d\n", bigA, bigB, smallA, smallB);
//
//	area = (bigA*bigB) - (smallA * smallB);
//	printf("%d", area * 7);
//}

#include <stdio.h>
int k, direction[10], length[10];
int sum = 0, BigA=0, BigB=0;

int main() {
	scanf("%d", &k);
	for (int i = 0; i < 6; i++) {
		scanf("%d %d", &direction[i], &length[i]);
	}

	for (int i = 0; i < 6; i++) {
		if (direction[i] == 1 || direction[i] == 2) {
			if (BigA < length[i]) {
				BigA = length[i];
			}
		}
		else if (direction[i] == 3 || direction[i] == 4) {
			if (BigB < length[i]) {
				BigB = length[i];
			}
		}
	}
	sum += length[0] * length[5];
	for (int i = 0; i < 5; i++){
		sum += length[i] * length[i + 1];
	}
	sum -= (BigA*BigB) * 2;

	printf("%d", sum * k);
}