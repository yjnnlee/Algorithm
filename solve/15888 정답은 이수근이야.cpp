#include <stdio.h>
#include <math.h>
double a, b, c, d, x1,x2;
int e[6] = { 2,4,8,16,32,64 };

bool isnum(int x) { //2제곱수?
	//int t = x & (x - 1);
	//if (t==0 || n != 1) return true;
	//else return false;

	for (int i = 0; i < 6; i++) {
		if (x == e[i]) return true;
	}
	return false;
}
int main() {

	scanf("%lf%lf%lf", &a, &b, &c);
	double d = b * b - 4 * a * c;
	x1 = ((-b) + sqrt(d)) / (2 * a);
	x2 = ((-b) - sqrt(d)) / (2 * a);
	//else if (d == 0) {
	//	x1 = ((-b) + sqrt(d)) / (2 * a);
	//	x2 = x1;
	//}
	//else {
	//	//int tx1 = -b / (2 * a);
	//	//int tx2 = sqrt(abs(d)) / 2 * a;
	//	//x1 = tx1 + tx2;
	//	//x2 = tx1 - tx2;
	//	//허근이면 무조건 둘다틀렸근
	//	printf("둘다틀렸근");
	//	return 0;
	//}
	//	printf(">%d %d %d %d %d", x1, x2, d, isnum(x1), isnum(x2));

	if (x1 == (int)x1 && x2 == (int)x2 && d > 0) {
		if (isnum((int)x1) && isnum((int)x2)) printf("이수근");
		else printf("정수근");
	}
	else printf("둘다틀렸근");
}
