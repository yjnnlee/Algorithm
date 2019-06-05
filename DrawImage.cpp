#include <stdio.h>
#include <Windows.h>
int main(){
	HDC hdc = GetWindowDC(GetForegroundWindow());
	FILE *fp = fopen("C:\\Temp\\lena.raw", "rb");
	if (fp == NULL) {
		fprintf(stderr, "에러");
		return 0;
	}
	char image[256][256];
	fread(image, 1, 256 * 256, fp);
	fclose(fp);
	for (int i = 0; i < 256; i++) {
		for (int j = 0; j < 256; j++) {
			int red = image[i][j];
			int green = image[i][j];
			int blue = image[i][j];
			SetPixel(hdc, j, i, RGB(red, green, blue));
		}
	}
	return 0;
}
