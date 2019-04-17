#include <stdio.h>
#include <Windows.h>
//int a[10], n;
int a[10] = { 100,150,50,78,89,12,56,38,99,66 }, n = 10;
int main() {
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	HDC hdc = GetWindowDC(GetForegroundWindow());

	for (int i = 1; i <= n; i++) {
		Rectangle(hdc, 0, 0, 800, 300);
		for (int j = 0; j < n-i; j++) {
			if (a[j] > a[j + 1]) {
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
		for (int i = 0; i < n; i++) {
			Rectangle(hdc, 200 + i * 50, 200 - a[i], 250 + i * 50, 200);
		}
		Sleep(1000);
	}
	for (int i = 0; i < n; i++) {
//		Rectangle(hdc, 200 + i * 50, 200 - a[i], 250 + i * 50, 200);
		printf("%d ", a[i]);
	}
}
