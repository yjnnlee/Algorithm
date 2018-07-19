#include <stdio.h>
int arr[] = { 1,2,3,4,5,6,7,8,9};

int Bin_Search(int a) {
	int r = 9;
	int l = 0;

	while (l <= r) {
		int m = (r + l) / 2;
		if (arr[m] == a) return 1;
		else if (a < arr[m]) r = m - 1;
		else l = m + 1;
	}
	return 0;
}

int main() {
	printf("%d\n", Bin_Search(0));
	printf("%d\n", Bin_Search(5));
	printf("%d\n", Bin_Search(9));
	printf("%d\n", Bin_Search(11));
}